#include "IntakeSubsystem.h"
#include "../RobotMap.h"
#include <iostream>
#include "Commands/IntakeIn.h"

IntakeSubsystem::IntakeSubsystem() :
		PIDSubsystem("IntakeSubsystem", 0.01, 0.0, 0.006)
{
	Arm = new Victor(INTAKE_MOTOR_ARM);

	IntakeRetracted = new DigitalInput(INTAKE_RETRACTED_SWITCH);
	IntakeAngle = new VexEncoder(INTAKE_ENCODER);
	SetAbsoluteTolerance(5);
	LiveWindow::GetInstance()->AddActuator("Intake", "Intake PID", GetPIDController());
}

void IntakeSubsystem::InitDefaultCommand()
{
//	IntakeAngle->Reset();
	SetDefaultCommand(new IntakeIn());
}

void IntakeSubsystem::Out()
{
	Enable();
	SetSetpoint(INTAKE_MINIMUM_DISTANCE + 326);
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
		SetSetpoint(INTAKE_MINIMUM_DISTANCE + 5);
//	}
}

double IntakeSubsystem::ReturnPIDInput() {
	float angle = IntakeAngle->GetAngle();
	SmartDashboard::PutNumber("IntakeAngle",angle);
	return angle;
}

void IntakeSubsystem::UsePIDOutput(double power){
	Arm->PIDWrite( - power );
}

void IntakeSubsystem::Reset(){
	IntakeAngle->Reset();
}



