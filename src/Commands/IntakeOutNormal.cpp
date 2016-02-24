#include "IntakeOutNormal.h"

IntakeOutNormal::IntakeOutNormal() : CommandBase("IntakeOutNormal")
{
	Requires(intake.get());
}

// Called just before this Command runs the first time
void IntakeOutNormal::Initialize()
{
	intake->SetSetpoint(606);
}

// Called repeatedly when this Command is scheduled to run
void IntakeOutNormal::Execute()
{
	intake->Enable();
	intake->SetSetpointRelative(oi->operatorController->GetRawAxis(3));

}

// Make this return true when this Command no longer needs to run execute()
bool IntakeOutNormal::IsFinished()
{
	return false;

}

// Called once after isFinished returns true
void IntakeOutNormal::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeOutNormal::Interrupted()
{

}
