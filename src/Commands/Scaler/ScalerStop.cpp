/**
 * Physically locks the scaler into position
 */

#include "ScalerStop.h"

ScalerStop::ScalerStop() : CommandBase("ScalerStop")
{
	Requires(scaler.get());
}

// Called just before this Command runs the first time
void ScalerStop::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ScalerStop::Execute()
{
	scaler->SetPositionLock(Relay::kForward);
}

// Make this return true when this Command no longer needs to run execute()
bool ScalerStop::IsFinished()
{
	return true;

}

// Called once after isFinished returns true
void ScalerStop::End()
{


}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScalerStop::Interrupted()
{
	scaler->SetDeploy(0);
}
