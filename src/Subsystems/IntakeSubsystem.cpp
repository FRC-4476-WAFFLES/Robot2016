/**
 * IntakeSubsystem is a class that keeps references to each of the
 * manipulators and sensors that are used by the intake arm.
 */


#include "IntakeSubsystem.h"
#include "../RobotMap.h"

IntakeSubsystem::IntakeSubsystem() :
		PIDSubsystem("IntakeSubsystem", 0.01, 0.0, 0.01)
{
	Arm = new Victor(INTAKE_MOTOR_ARM);
	SetAbsoluteTolerance(10.000);

	IntakeAngle = new VexEncoder(INTAKE_ENCODER);
	LiveWindow::GetInstance()->AddActuator("Intake", "Intake PID", GetPIDController());
}

void IntakeSubsystem::InitDefaultCommand()
{
	// No default command
}

// Sets the motor to move at a speed, also disables the pid
void IntakeSubsystem::Move(float moveSpeed)
{
	Disable();
	Arm->SetSpeed(moveSpeed);
}

// Input for the PID in this PIDSubsystem
double IntakeSubsystem::ReturnPIDInput() {
	float angle = IntakeAngle->GetAngle();
	return angle;
}

// Output for the PID in this PIDSubsystem
void IntakeSubsystem::UsePIDOutput(double power){
	Arm->PIDWrite( power );
}

// Resets the encoder so that it is in the first rotation
void IntakeSubsystem::Reset(){
	IntakeAngle->Reset();
}



