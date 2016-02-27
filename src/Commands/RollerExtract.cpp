#include <Commands/RollerExtract.h>

RollerExtract::RollerExtract()
{
	Requires(roller.get());
}

// Called just before this Command runs the first time
void RollerExtract::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RollerExtract::Execute()
{
	//Setting roller speed to - meaning it will make the balls go out of intake
	roller->Roll(-1.0);
}

// Make this return true when this Command no longer needs to run execute()
bool RollerExtract::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RollerExtract::End()
{
	roller->Roll(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RollerExtract::Interrupted()
{
	roller->Roll(0);
}
