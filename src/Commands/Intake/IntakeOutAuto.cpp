#include "IntakeOutAuto.h"

////////////////DISCRIPTION//////////////////
// sets the PID intake out set point to 606 encoder Ticks.~~ends~~


IntakeOutAuto::IntakeOutAuto() : CommandBase("IntakeOutAuto")
{
	Requires(intake.get());
}

// Called just before this Command runs the first time
void IntakeOutAuto::Initialize()
{
	intake->SetSetpoint(343);
}

// Called repeatedly when this Command is scheduled to run
void IntakeOutAuto::Execute()
{
	intake->Enable();
	intake->SetSetpointRelative(oi->operatorController->GetRawAxis(3));

}

// Make this return true when this Command no longer needs to run execute()
bool IntakeOutAuto::IsFinished()
{
	double error = intake->GetSetpoint() - intake->GetPosition();
	return error < 10 && error > -10;
}

// Called once after isFinished returns true
void IntakeOutAuto::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeOutAuto::Interrupted()
{

}
