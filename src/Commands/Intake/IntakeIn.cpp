#include "IntakeIn.h"

////////////////DESCRIPTION//////////////////
//sets the intake  in PID set point to 300.


IntakeIn::IntakeIn()
{
	Requires(intake.get());
}

// Called just before this Command runs the first time
void IntakeIn::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void IntakeIn::Execute()
{
	//Intake inside setpoint/position
	intake->Enable();
	intake->SetSetpoint(30);
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeIn::IsFinished()
{
	return intake->OnTarget();
}

// Called once after isFinished returns true
void IntakeIn::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeIn::Interrupted()
{

}
