#include "ADefensesGoToAngle.h"

ADefensesGoToAngle::ADefensesGoToAngle(double angle) : CommandBase("ADefensesGoToAngle")
{
	this->angle = angle;
	Requires(GoToAngle.get());
}

// Called just before this Command runs the first time
void ADefensesGoToAngle::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ADefensesGoToAngle::Execute()
{
	GoToAngle->SetSetpoint(angle);
}

// Make this return true when this Command no longer needs to run execute()
bool ADefensesGoToAngle::IsFinished()
{
	return GoToAngle->OnTarget();
}

// Called once after isFinished returns true
void ADefensesGoToAngle::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ADefensesGoToAngle::Interrupted()
{

}
