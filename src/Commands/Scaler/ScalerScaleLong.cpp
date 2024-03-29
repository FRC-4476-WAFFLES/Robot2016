/**
 * Takes a length as a parameter and goes to that length
 */

#include "ScalerScaleLong.h"

ScalerScaleLong::ScalerScaleLong(float Length) : CommandBase("ScalerScaleLong")
{
	LikeLength = Length;
	Requires(scaler.get());
	longStopTimer = new Timer();
}

// Called just before this Command runs the first time
void ScalerScaleLong::Initialize()
{
	longStopTimer->Reset();
	longStopTimer->Start();
}

// Called repeatedly when this Command is scheduled to run
void ScalerScaleLong::Execute()
{
	if (scaler->ScaleEncoder()>LikeLength) {
		scaler->ScalingMotors(0.75);
	}
	else {
		//If it works well, increase to 0.5 then 0.75 and then full
		scaler->ScalingMotors(-0.75);
	}
	//If it works well, increase to 0.5 then 0.75 and then full
	if(longStopTimer->Get() < 2)
		scaler->SetDeploy(-0.25);
	else
		scaler->SetDeploy(0);

	scaler->SetPositionLock(Relay::kForward);
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
	scaler->SetPositionLock(Relay::kOff);
	scaler->SetDeploy(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScalerScaleLong::Interrupted()
{
	scaler->ScalingMotors(0);
	scaler->SetPositionLock(Relay::kOff);
	scaler->SetDeploy(0);
}
