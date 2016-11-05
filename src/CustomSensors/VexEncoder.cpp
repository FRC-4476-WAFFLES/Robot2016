#include <CustomSensors/VexEncoder.h>
#include <cmath>

VexEncoder::VexEncoder(int port, float tearpoint):
	input(port),
	counter_high(),
	counter_low(),
	tearpoint(tearpoint),
	last_int(0.0),
	last_fract(0.0),
	first(true),
	error(false),
	error_count(0)
{
	counter_high.SetUpSource(input);
	counter_high.SetSemiPeriodMode(true);

	counter_low.SetUpSource(input);
	counter_low.SetSemiPeriodMode(false);
}

void VexEncoder::prints() {
	SmartDashboard::PutNumber("error_count ", error_count);
}

float VexEncoder::GetAngle() {
	float rawAngle = GetRawAngle();

	// Throw away values that produced errors
	if(error) {
		return last_fract + (last_int * 360.0);
	}

	// Reset on the first run through
	if(first) {
		// Account for the tearpoint.
		if(rawAngle > tearpoint) {
			last_int = -1;
		} else {
			last_int = 0;
		}

		last_fract = rawAngle;

		// The next run through won't be the first
		first = false;
		return rawAngle + (last_int * 360.0);
	}

	// Find the shortest path to the new value
	if(rawAngle-last_fract > 180.0){
		last_int--;
	} else if (rawAngle-last_fract < -180.0){
		last_int++;
	}

	// Calculate the new value
	float newValue = rawAngle + (last_int * 360.0);

	// Remember this for next time
	last_fract = rawAngle;
	return newValue;
}

double VexEncoder::PIDGet() {
	return GetAngle();
}

float VexEncoder::GetRawAngle() {
	float high = counter_high.GetPeriod();
	float low = counter_low.GetPeriod();

	// Calculate the duty cycle and multiply by 360.0 degrees
	float sum = (high + low);
	float angle = (high / sum) * 360.0;

	error =
		// Check for angle in range
		angle > 360.0 || angle < 0.0 ||
		// Check for pulse period in range (taken from datasheet https://content.vexrobotics.com/vexpro/pdf/Magnetic-Encoder-User's-Guide-01282016.pdf)
		sum > (1.0/220.0) || sum < (1.0/268.0);

	if(error) {
		error_count++;
	}

	return angle;
}

void VexEncoder::Reset() {
	// Reset the angle such that it is in its first rotation.
	first = true;
}
