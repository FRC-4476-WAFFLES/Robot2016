#include "ScalerRetract.h"

ScalerRetract::ScalerRetract() : CommandBase("ScalerRetract")
{
	Requires(scaler.get());
}

// Called just before this Command runs the first time
void ScalerRetract::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ScalerRetract::Execute()
{
	scaler->ScalingMotors(0.1);
}

// Make this return true when this Command no longer needs to run execute()
bool ScalerRetract::IsFinished()
{
	return scaler->ScaleEncoder()>1;
}

// Called once after isFinished returns true
void ScalerRetract::End()
{
	scaler->ScalingMotors(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScalerRetract::Interrupted()
{
	scaler->ScalingMotors(0);
}
