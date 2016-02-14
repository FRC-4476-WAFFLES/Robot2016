#include "IntakeHalfWayPoint.h"

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
	intake->Enable();
	intake->SetSetpoint(171 + INTAKE_MINIMUM_DISTANCE);
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
