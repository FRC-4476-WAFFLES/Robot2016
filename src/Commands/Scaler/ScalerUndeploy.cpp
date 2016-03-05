/**
 * Retracts the scaler inside the robot
 */

#include "ScalerUndeploy.h"

ScalerUndeploy::ScalerUndeploy() : CommandBase("ScalerUndeploy")
{
	Requires(scaler.get());
}

// Called just before this Command runs the first time
void ScalerUndeploy::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ScalerUndeploy::Execute()
{
	scaler->SetDeploy(0.25);
}

// Make this return true when this Command no longer needs to run execute()
bool ScalerUndeploy::IsFinished()
{
	return scaler->GetDeploy()>630;

}

// Called once after isFinished returns true
void ScalerUndeploy::End()
{
	scaler->SetDeploy(0.0);

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScalerUndeploy::Interrupted()
{
	scaler->SetDeploy(0);
}
