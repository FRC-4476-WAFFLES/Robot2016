/**
 * Releases the locking mechanism on the robot
 */

#include "ScalerRelease.h"

ScalerRelease::ScalerRelease() : CommandBase("ScalerRelease")
{
	Requires(scaler.get());
}

// Called just before this Command runs the first time
void ScalerRelease::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ScalerRelease::Execute()
{
	scaler->SetPositionLock(Relay::kReverse);
}

// Make this return true when this Command no longer needs to run execute()
bool ScalerRelease::IsFinished()
{
	return true;

}

// Called once after isFinished returns true
void ScalerRelease::End()
{


}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScalerRelease::Interrupted()
{
	scaler->SetDeploy(0);
}
