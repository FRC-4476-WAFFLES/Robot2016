#include "ScalerRetract.h"

ScalerRetract::ScalerRetract() : CommandBase("ScalerRetract")
{

}

// Called just before this Command runs the first time
void ScalerRetract::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ScalerRetract::Execute()
{
	Scaler->ScalingMotors(1);

}

// Make this return true when this Command no longer needs to run execute()
bool ScalerRetract::IsFinished()
{
	return Scaler->ScaleEncoder()>1;
}

// Called once after isFinished returns true
void ScalerRetract::End()
{
	Scaler->ScalingMotors(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScalerRetract::Interrupted()
{

}
