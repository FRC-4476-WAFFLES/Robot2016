/**
 * Moves the scaler arm up.
 */

#include "ScalerDeploy.h"

ScalerDeploy::ScalerDeploy() : CommandBase("ScalerDeploy")
{
	Requires(scaler.get());
}

// Called just before this Command runs the first time
void ScalerDeploy::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ScalerDeploy::Execute()
{

	scaler->SetDeploy(-0.25);
}

// Make this return true when this Command no longer needs to run execute()
bool ScalerDeploy::IsFinished()
{
	return scaler->GetDeploy()>630;

}

// Called once after isFinished returns true
void ScalerDeploy::End()
{
	scaler->SetDeploy(0.01);

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScalerDeploy::Interrupted()
{
	scaler->SetDeploy(0);
}
