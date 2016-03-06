/*
 * RollerSuckTime.cpp
 *
 *  Created on: Mar 6, 2016
 *      Author: WAFFLES_Guest
 */

#include <Commands/Roller/RollerSuckTime.h>

RollerSuckTime::RollerSuckTime(double time) {
	Requires(roller.get());
	timer = new Timer();
	this->time = time;
}

// Called just before this Command runs the first time
void RollerSuckTime::Initialize()
{
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void RollerSuckTime::Execute()
{
	//Setting speed to positive meaning you are taking in the balls with roller
	roller->Roll(-1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool RollerSuckTime::IsFinished()
{
	return timer->Get() > time;
}

// Called once after isFinished returns true
void RollerSuckTime::End()
{
	roller->Roll(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RollerSuckTime::Interrupted()
{
	roller->Roll(0);
}


