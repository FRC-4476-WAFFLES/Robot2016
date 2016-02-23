/*
 * VexEncoder.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: WAFFLES_Guest
 */

#include <CustomSensors/VexEncoder.h>
#include <math.h>

VexEncoder::VexEncoder(int port) {
	counter = new Counter(port);
	counter->SetSemiPeriodMode(true);
	counter->SetSamplesToAverage(1);
	GetAngle();
	lastInt = 0;
	first = true;
}

float VexEncoder::GetAngle() {
	float rawAngle = GetRawAngle();

	//SmartDashboard::PutNumber("RawAngle", rawAngle);

	// Throw away angles outside the acceptable range
	if(rawAngle > 360 || rawAngle<0) {
		return lastFract + (lastInt * 360.0);
	}

	// Reset on the first run through
	if(first) {
		lastInt = 0;
		lastFract = rawAngle;
		first = false;
		return rawAngle;
	}

	// Find the shortest path to the new value
	if(rawAngle-lastFract > 180.0){
		lastInt--;
	} else if (rawAngle-lastFract < -180.0){
		lastInt++;
	}

	// Calculate the new value
	float newValue = rawAngle + ((float)lastInt * 360.0);

	//SmartDashboard::PutNumber("Angle", newValue);

	// Remember this for next time
	lastFract = rawAngle;
	return newValue;
}


float VexEncoder::GetRawAngle() {
	// PWM is 220Hz (from the docs) (And convert to degrees).
	float angle = (counter->GetPeriod()*240.0)*360.0;
	return angle;
}

void VexEncoder::Reset() {
	// Reset the angle such that it is in its first rotation.
	first = true;
}
