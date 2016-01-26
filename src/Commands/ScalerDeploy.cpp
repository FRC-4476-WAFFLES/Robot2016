#include "ScalerDeploy.h"

ScalerDeploy::ScalerDeploy() : CommandBase("ScalerDeploy")
{

}

// Called just before this Command runs the first time
void ScalerDeploy::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ScalerDeploy::Execute()
{
	scaler->SetDeploy(1);
}

// Make this return true when this Command no longer needs to run execute()
bool ScalerDeploy::IsFinished()
{
	return scaler->GetDeploy()>1;
}

// Called once after isFinished returns true
void ScalerDeploy::End()
{
	scaler->SetDeploy(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScalerDeploy::Interrupted()
{
	scaler->SetDeploy(0);
}
