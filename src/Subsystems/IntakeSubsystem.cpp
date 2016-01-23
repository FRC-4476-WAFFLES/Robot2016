#include "IntakeSubsystem.h"
#include "../RobotMap.h"

IntakeSubsystem::IntakeSubsystem() :
		PIDSubsystem("IntakeSubsystem", 0.01, 0.00, 0.00)
{
	Arm = new Victor(2);

	IntakeRetracted = new DigitalInput(0);
	IntakeAngle = new Encoder(1,2);
}

void IntakeSubsystem::InitDefaultCommand()
{
	//SetDefaultCommand(new MySpecialCommand());
}

void IntakeSubsystem::Out()
{
	SetSetpoint(1);
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




