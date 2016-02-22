#include "ScalerScale.h"

ScalerScale::ScalerScale() : CommandBase("ScalerScale")
{
	Requires(scaler.get());
}

// Called just before this Command runs the first time
void ScalerScale::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ScalerScale::Execute()
{
	scaler->ScalingMotors(-0.75);
}

// Make this return true when this Command no longer needs to run execute()
bool ScalerScale::IsFinished()
{
	return scaler->ScaleEncoder()>1;
}

// Called once after isFinished returns true
void ScalerScale::End()
{
	scaler->ScalingMotors(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScalerScale::Interrupted()
{
	scaler->ScalingMotors(0);
}
