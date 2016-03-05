/**
 * Takes a length as a parameter and goes to that length
 */

#include "ScalerScaleLong.h"

ScalerScaleLong::ScalerScaleLong(float Length) : CommandBase("ScalerScaleLong")
{
	LikeLength = Length;
	Requires(scaler.get());
}

// Called just before this Command runs the first time
void ScalerScaleLong::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ScalerScaleLong::Execute()
{
	if (scaler->ScaleEncoder()>LikeLength) {
		scaler->ScalingMotors(0.25);
	}
	else {
		scaler->ScalingMotors(-0.25);
	}
	scaler->SetDeploy(-0.25);
}
// Make this return true when this Command no longer needs to run execute()
bool ScalerScaleLong::IsFinished()
{
	double error = scaler->ScaleEncoder() - LikeLength ;
	return error < 10 && error > -10;
}

// Called once after isFinished returns true
void ScalerScaleLong::End()
{
	scaler->ScalingMotors(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScalerScaleLong::Interrupted()
{
	scaler->ScalingMotors(0);
}
