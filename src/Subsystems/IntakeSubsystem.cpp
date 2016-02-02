#include "IntakeSubsystem.h"
#include "../RobotMap.h"
#include <iostream>

IntakeSubsystem::IntakeSubsystem() :
		PIDSubsystem("IntakeSubsystem", 0.01, 0.00, 0.00)
{
	Arm = new Victor(INTAKE_MOTOR_ARM);

	IntakeRetracted = new DigitalInput(INTAKE_RETRACTED_SWITCH);
	IntakeAngle = new VexEncoder(INTAKE_ENCODER);
}

void IntakeSubsystem::InitDefaultCommand()
{
	//SetDefaultCommand(new MySpecialCommand());
}

void IntakeSubsystem::Out()
{
	Enable();
	SetSetpoint(550);
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
		IntakeAngle->Reset();
	} else {
		Enable();
		SetSetpoint(230);
	}
}

double IntakeSubsystem::ReturnPIDInput() {
	float angle = IntakeAngle->GetAngle();
	printf("Angle: %.9f\n", angle);
	return angle;
}

void IntakeSubsystem::UsePIDOutput(double power){
	Arm->PIDWrite(power);
}




