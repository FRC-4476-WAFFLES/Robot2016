#include "IntakeOut.h"

IntakeOut::IntakeOut() : CommandBase("IntakeOut")
{
	Requires(intake.get());
}

// Called just before this Command runs the first time
void IntakeOut::Initialize()
{
	intake->SetSetpoint(346);
}

// Called repeatedly when this Command is scheduled to run
void IntakeOut::Execute()
{
	intake->Enable();
	intake->SetSetpointRelative(oi->operatorController->GetRawAxis(3));

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
