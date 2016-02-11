#include "ScalerSubsystem.h"
#include "../RobotMap.h"

ScalerSubsystem::ScalerSubsystem() :
		Subsystem("ScalerSubsystem")
{

	 ScalingMotor1 = new Victor(SCALER_CLIMB_1);
	 ScalingMotor2 = new Victor(SCALER_CLIMB_2);
	 ScalingEncoder = new Encoder(SCALER_CLIMB_ENCODER_A, SCALER_CLIMB_ENCODER_B);
	 DeployingEncoder = new Encoder(SCALER_DEPLOY_ENCODER_A, SCALER_DEPLOY_ENCODER_B);
	 DeployingVictor = new Victor(SCALER_DEPLOYER);
	 PositionLock = new Relay(SCALER_POSITION_LOCK);
}

void ScalerSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.

}


// Put methods for controlling this subsystem
// here. Call these from Commands.

	double ScalerSubsystem::GetDeploy()
	{
		return DeployingEncoder->Get();
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
