#include "DriveSubsystem.h"
#include "../RobotMap.h"
#include "Commands/OperatorDrive.h"
DriveSubsystem::DriveSubsystem() :
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

void DriveSubsystem::Drive(Joystick* right, Joystick* left)
{
	RightMotorFront->SetSpeed(right->GetY());
	LeftMotorFront->SetSpeed(left->GetY());
	RightMotorBack->SetSpeed(right->GetY());
	LeftMotorBack->SetSpeed(left->GetY());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

