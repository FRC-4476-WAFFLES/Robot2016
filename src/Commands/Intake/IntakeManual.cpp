#include "IntakeManual.h"

////////////////DISCRIPTION//////////////////
//allows the operator to manually adjust the intake tilt.

IntakeManual::IntakeManual() : CommandBase()
{
	Requires(intake.get());
}

// Called just before this Command runs the first time
void IntakeManual::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void IntakeManual::Execute()
{
	//Use the thumbstick to move the intake manually(no setpoints)
	float speed = oi.get()->operatorController->GetY();
	intake.get()->Move(speed*0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeManual::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IntakeManual::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeManual::Interrupted()
{

}
