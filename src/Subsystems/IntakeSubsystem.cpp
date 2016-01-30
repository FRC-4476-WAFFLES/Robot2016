#include "IntakeSubsystem.h"
#include "../RobotMap.h"
#include "Commands/IntakeManual.h"
IntakeSubsystem::IntakeSubsystem() :
		PIDSubsystem("IntakeSubsystem", 1.0, 0.00, 0.00)
{
	Arm = new Victor(7);

	IntakeRetracted = new DigitalInput(0);
	IntakeAngle = new Encoder(1,2);

}

void IntakeSubsystem::InitDefaultCommand()
{
	SetDefaultCommand(new IntakeManual());
	//SetDefaultCommand(new MySpecialCommand());
}

void IntakeSubsystem::Out()
{
	SetSetpoint(20);
	Enable();

}

void IntakeSubsystem::In()
{


	if(IntakeRetracted->Get()){
		Disable();
		Arm->SetSpeed(0);
		IntakeAngle->Reset();

	} else {
		SetSetpoint(0);
		Enable();
	}
}

double IntakeSubsystem::ReturnPIDInput() {
	return IntakeAngle->PIDGet();
}

void IntakeSubsystem::UsePIDOutput(double power){

	Arm->PIDWrite(power);
}

void IntakeSubsystem::Move(float speed){

	Disable();
	Arm->SetSpeed(speed);

}



