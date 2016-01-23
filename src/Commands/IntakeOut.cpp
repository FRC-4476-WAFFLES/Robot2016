#include "IntakeOut.h"

IntakeOut::IntakeOut() : CommandBase("IntakeOut")
{
	Requires(intake.get());
}

// Called just before this Command runs the first time
void IntakeOut::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void IntakeOut::Execute()
{
	intake->Out();
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeOut::IsFinished()
{
	return intake->OnTarget();
}

// Called once after isFinished returns true
void IntakeOut::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeOut::Interrupted()
{

}
