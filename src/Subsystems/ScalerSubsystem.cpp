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


// Put methods for controlling this subsystem
// here. Call these from Commands.

	double ScalerSubsystem::GetDeploy()
	{
		double angle = DeployingVexEncoder->GetAngle();
		SmartDashboard::PutNumber("scalerTiltAngle", angle);
		return angle;
	}
	void ScalerSubsystem::SetDeploy(double Speed)
	{
		//Speed = 0.1;
		DeployingVictor->SetSpeed(-Speed);
	}

	 void ScalerSubsystem::ScalingMotors(double Speed)
	 {
		 //speed = 0.1
			SmartDashboard::PutNumber("scalingSpeed", Speed);
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
