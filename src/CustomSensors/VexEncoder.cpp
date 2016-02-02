/*
 * VexEncoder.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: WAFFLES_Guest
 */

#include <CustomSensors/VexEncoder.h>

VexEncoder::VexEncoder(int port) {
	start = 0;
	end = 0;
	counter = new Counter(port);
	counter->SetSemiPeriodMode(true);
}

VexEncoder::VexEncoder(int port, float s, float e): VexEncoder(port) {
	start = s;
	end = e;
}
float VexEncoder::GetPeriod(){
	float counterValue = counter->GetPeriod()*220;
	if(counterValue<start){
		counterValue = counterValue + 1;
	}
	return counterValue;
}

VexEncoder::~VexEncoder() {
	// TODO Auto-generated destructor stub
}

