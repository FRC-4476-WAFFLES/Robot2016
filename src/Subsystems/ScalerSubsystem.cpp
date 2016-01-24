#include "ScalerSubsystem.h"
#include "../RobotMap.h"

ScalerSubsystem::ScalerSubsystem() :
		Subsystem("ScalerSubsystem")
{

	 ScalingMotor1 = new Victor(7);
	 ScalingMotor2 = new Victor(8);
	 ScalingEncoder = new Encoder(3,4);
	 DeployingEncoder = new Encoder(5,6);
	 DeployingVictor = new Victor(9);
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
