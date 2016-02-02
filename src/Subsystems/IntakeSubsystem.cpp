#include "IntakeSubsystem.h"
#include "../RobotMap.h"
#include <iostream>

IntakeSubsystem::IntakeSubsystem() :
		PIDSubsystem("IntakeSubsystem", 0.01, 0.00, 0.00)
{
	Arm = new Victor(INTAKE_MOTOR_ARM);

	IntakeRetracted = new DigitalInput(INTAKE_RETRACTED_SWITCH);
	IntakeAngle = new VexEncoder(INTAKE_ENCODER, .6, .64);
}

void IntakeSubsystem::InitDefaultCommand()
{
	//SetDefaultCommand(new MySpecialCommand());
}

void IntakeSubsystem::Out()
{
	Enable();
	SetSetpoint(.541);
}

void IntakeSubsystem::Move(float moveSpeed)
{
	Disable();
	Arm->SetSpeed(moveSpeed);
}

void IntakeSubsystem::In()
{
	if(IntakeRetracted->Get()){
		Disable();
		Arm->SetSpeed(0);
//		IntakeAngle->Reset();
	} else {
		Enable();
		SetSetpoint(.630);
	}
}

double IntakeSubsystem::ReturnPIDInput() {
	// The PWM frequency is 220Hz
	float period = IntakeAngle->GetPeriod()*220.0;
	printf("Period: %.9f\n", period);
	return period;
}

void IntakeSubsystem::UsePIDOutput(double power){
	Arm->PIDWrite(power);
}




