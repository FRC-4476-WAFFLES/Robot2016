#include "IntakeHalfWayPoint.h"

////////////////DESCRIPTION//////////////////
//sets the PID set point in the intake Subsystem to 455


IntakeHalfWayPoint::IntakeHalfWayPoint() : CommandBase("IntakeHalfWayPoint")
{
	Requires(intake.get());
}

// Called just before this Command runs the first time
void IntakeHalfWayPoint::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void IntakeHalfWayPoint::Execute()
{
	//Intake half way point
	intake->Enable();
	intake->SetSetpoint(385);
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeHalfWayPoint::IsFinished()
{
	return intake->OnTarget();
}

// Called once after isFinished returns true
void IntakeHalfWayPoint::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeHalfWayPoint::Interrupted()
{

}
