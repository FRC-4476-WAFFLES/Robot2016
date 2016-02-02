/*
 * VexEncoder.h
 *
 *  Created on: Feb 1, 2016
 *      Author: WAFFLES_Guest
 */

#ifndef SRC_CUSTOMSENSORS_VEXENCODER_H_
#define SRC_CUSTOMSENSORS_VEXENCODER_H_
#include "WPILib.h"
class VexEncoder {
private:
	Counter* counter;
	float start;
	float end;
public:
	VexEncoder(int port);
	VexEncoder(int port, float start, float end);
	virtual ~VexEncoder();
	float GetPeriod();

};

#endif /* SRC_CUSTOMSENSORS_VEXENCODER_H_ */
