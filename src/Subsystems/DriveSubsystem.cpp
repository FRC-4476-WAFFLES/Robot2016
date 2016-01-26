#include "DriveSubsystem.h"
#include "../RobotMap.h"
#include "Commands/OperatorDrive.h"

DriveSubsystem::DriveSubsystem():
		Subsystem("DriveSubsystem")
{
	 RightMotorFront = new Victor(2);
	 RightMotorBack = new  Victor(3);
	 LeftMotorFront = new Victor(0);
	 LeftMotorBack = new Victor(1);
}

void DriveSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new OperatorDrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveSubsystem::Drive(Joystick* left, Joystick* right)
{
	Drive(left->GetY(), right->GetY());
}

void DriveSubsystem::Drive(double left, double right)
{
	RightMotorFront->SetSpeed(right);
	LeftMotorFront->SetSpeed(-left);
	RightMotorBack->SetSpeed(right);
	LeftMotorBack->SetSpeed(-left);
}
