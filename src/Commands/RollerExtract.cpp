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
	roller->Roll(-1);
}

// Make this return true when this Command no longer needs to run execute()
bool RollerExtract::IsFinished()
{
	return true;
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
