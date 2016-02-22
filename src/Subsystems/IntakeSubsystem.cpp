#include "IntakeSubsystem.h"
#include "../RobotMap.h"
#include <iostream>
#include "Commands/IntakeIn.h"

IntakeSubsystem::IntakeSubsystem() :
		PIDSubsystem("IntakeSubsystem", 0.01, 0.0, 0.01)
{
	Arm = new Victor(INTAKE_MOTOR_ARM);


	IntakeAngle = new VexEncoder(INTAKE_ENCODER);
	LiveWindow::GetInstance()->AddActuator("Intake", "Intake PID", GetPIDController());
}

void IntakeSubsystem::InitDefaultCommand()
{
	SetDefaultCommand(new IntakeIn());
}



void IntakeSubsystem::Move(float moveSpeed)
{
	Disable();
	Arm->SetSpeed(moveSpeed);
}

double IntakeSubsystem::ReturnPIDInput() {
	float angle = IntakeAngle->GetAngle();
	return angle;
}

void IntakeSubsystem::UsePIDOutput(double power){
	Arm->PIDWrite( - power );
}

void IntakeSubsystem::Reset(){
	IntakeAngle->Reset();
}



