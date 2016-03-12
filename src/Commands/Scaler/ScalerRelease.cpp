/**
 * Releases the locking mechanism on the robot
 */
#include "stdio.h"
#include "ScalerRelease.h"

ScalerRelease::ScalerRelease() : CommandBase("ScalerRelease")
{
	Requires(scaler.get());
	t = new Timer();
}

// Called just before this Command runs the first time
void ScalerRelease::Initialize()
{
	printf("Release");
	t->Reset();
	t->Start();

}

// Called repeatedly when this Command is scheduled to run
void ScalerRelease::Execute()
{
	scaler->SetPositionLock(Relay::kForward);

}

// Make this return true when this Command no longer needs to run execute()
bool ScalerRelease::IsFinished()
{
	return t->Get() > 1;
	scaler->SetPositionLock(Relay::kOff);
}

// Called once after isFinished returns true
void ScalerRelease::End()
{
	scaler->SetPositionLock(Relay::kOff);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScalerRelease::Interrupted()
{
	scaler->SetDeploy(0);
}
