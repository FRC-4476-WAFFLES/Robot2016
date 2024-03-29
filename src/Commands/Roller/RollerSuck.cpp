#include "RollerSuck.h"

////////////////DISCRIPTION//////////////////
// Runs the roller in the direction that will suck balls into the robot.

RollerSuck::RollerSuck()
{
	Requires(roller.get());
}

// Called just before this Command runs the first time
void RollerSuck::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void RollerSuck::Execute()
{
	//Setting speed to positive meaning you are taking in the balls with roller
	roller->Roll(1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool RollerSuck::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RollerSuck::End()
{
	roller->Roll(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RollerSuck::Interrupted()
{
	roller->Roll(0);
}
