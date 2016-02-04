#include "IntakeSubsystem.h"
#include "../RobotMap.h"
#include <iostream>
#include "Commands/IntakeIn.h"

IntakeSubsystem::IntakeSubsystem() :
		PIDSubsystem("IntakeSubsystem", 0.02, 0.0001, 0.000)
{
	Arm = new Victor(INTAKE_MOTOR_ARM);

	IntakeRetracted = new DigitalInput(INTAKE_RETRACTED_SWITCH);
	IntakeAngle = new VexEncoder(INTAKE_ENCODER);
	SetAbsoluteTolerance(5);
	Enable();
}

void IntakeSubsystem::InitDefaultCommand()
{
	SetDefaultCommand(new IntakeIn());
}

void IntakeSubsystem::Out()
{
	Enable();
	SetSetpoint(896);
}

void IntakeSubsystem::Move(float moveSpeed)
{
	Disable();
	Arm->SetSpeed(moveSpeed);
}

void IntakeSubsystem::In()
{
//	if(IntakeRetracted->Get()){
//		Disable();
//		Arm->SetSpeed(0);
//		IntakeAngle->Reset();
//	}else {
		Enable();
		SetSetpoint(572);
//	}
}

double IntakeSubsystem::ReturnPIDInput() {
	float angle = IntakeAngle->GetAngle();
	SmartDashboard::PutNumber("IntakeAngle",angle);
	return angle;
}

void IntakeSubsystem::UsePIDOutput(double power){
	float limit = 0.5;
	Arm->PIDWrite( - power * limit);
}

void IntakeSubsystem::Reset(){
	IntakeAngle->Reset();
}



