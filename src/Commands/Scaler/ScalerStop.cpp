/**
 * Physically locks the scaler into position
 */
#include "stdio.h"
#include "ScalerStop.h"

ScalerStop::ScalerStop() : CommandBase("ScalerStop")
{
	Requires(scaler.get());
	t = new Timer();
}

// Called just before this Command runs the first time
void ScalerStop::Initialize()
{
	t-> Reset();
	t-> Start();
}

// Called repeatedly when this Command is scheduled to run
void ScalerStop::Execute()
{
	scaler->SetPositionLock(Relay::kReverse);
}

// Make this return true when this Command no longer needs to run execute()
bool ScalerStop::IsFinished()
{
	return t->Get() > 1;

}

// Called once after isFinished returns true
void ScalerStop::End()
{
	scaler->SetPositionLock(Relay::kOff);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScalerStop::Interrupted()
{
	scaler->SetDeploy(0);
	scaler->SetPositionLock(Relay::kOff);
}
