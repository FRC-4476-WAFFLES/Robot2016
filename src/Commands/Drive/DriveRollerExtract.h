/*
 * DriveAuto.h
 *
 *  Created on: Feb 27, 2016
 *      Author: Robotics-1
 */

#ifndef DRIVE_ROLLER_EXTRACT_H_
#define DRIVE_ROLLER_EXTRACT_H_

#include "CommandBase.h"

class DriveRollerExtract: public CommandBase {
private:
	Timer* t;
public:
	DriveRollerExtract();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
