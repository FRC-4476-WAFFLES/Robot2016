/**
 * ScalerSubsystem is a class that keeps references to each of the
 * manipulators and sensors that are needed for scaling.
 */


#include "ScalerSubsystem.h"
#include "../RobotMap.h"

ScalerSubsystem::ScalerSubsystem() :
		Subsystem("ScalerSubsystem")
{
	 ScalingMotor1 = new Victor(SCALER_CLIMB_1);
	 ScalingMotor2 = new Victor(SCALER_CLIMB_2);
	 ScalingEncoder = new Encoder(SCALER_CLIMB_ENCODER_A, SCALER_CLIMB_ENCODER_B);
	 DeployingVexEncoder = new VexEncoder(SCALING_DEPLOYING_ENCODER);
	 DeployingVictor = new Victor(SCALER_DEPLOYER);
	 PositionLock = new Relay(SCALER_POSITION_LOCK);
}

void ScalerSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
}

double ScalerSubsystem::GetDeploy()
{
	return DeployingVexEncoder->GetAngle();
}

void ScalerSubsystem::SetDeploy(double Speed)
{
	DeployingVictor->SetSpeed(Speed);
}

void ScalerSubsystem::ScalingMotors(double Speed)
{
	ScalingMotor1->SetSpeed(Speed);
	ScalingMotor2->SetSpeed(Speed);
}

double ScalerSubsystem::ScaleEncoder()
{
	return ScalingEncoder->Get();
}

void ScalerSubsystem::ReverseSpool(double Speed)
{
	ScalingMotor1->SetSpeed(-Speed);
	ScalingMotor2->SetSpeed(-Speed);
}

void ScalerSubsystem::SetPositionLock(Relay::Value JustOneLastTime){
	PositionLock->Set(JustOneLastTime);
}
