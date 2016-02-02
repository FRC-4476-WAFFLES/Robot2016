/*
 * VexEncoder.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: WAFFLES_Guest
 */

#include <CustomSensors/VexEncoder.h>
#include <math.h>

VexEncoder::VexEncoder(int port) {
	lastInt = 0;
	counter = new Counter(port);
	counter->SetSemiPeriodMode(true);
	lastFract = GetRawAngle();
}

float VexEncoder::GetAngle() {
	float rawAngle = GetRawAngle();

	// Find the shortest path to the new value
	if(rawAngle-lastFract > 180.0){
		lastInt--;
	} else if (rawAngle-lastFract < -180.0){
		lastInt++;
	}

	// Calculate the new value
	float newValue = rawAngle + ((float)lastInt * 360.0);

	// Remember this for next time
	lastFract = rawAngle;
	return newValue;
}


float VexEncoder::GetRawAngle() {
	// PWM is 220Hz (from the docs) (And convert to degrees).
	float angle = (counter->GetPeriod()*244.0)*360.0;
	return angle;
}

void VexEncoder::Reset() {
	// Reset the angle such that it is in its first rotation.
	lastInt = 0;
}
