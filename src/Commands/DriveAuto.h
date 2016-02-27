/*
 * DriveAuto.h
 *
 *  Created on: Feb 27, 2016
 *      Author: Robotics-1
 */

#ifndef DRIVE_AUTO_H_
#define DRIVE_AUTO_H_

#include "CommandBase.h"

class DriveAuto: public CommandBase {
private:
	double distance;
	double angle;
public:
	DriveAuto(double distance, double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
