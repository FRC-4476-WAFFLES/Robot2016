#include "DriveSubsystem.h"
#include "../RobotMap.h"
#include "Commands/OperatorDrive.h"
DriveSubsystem::DriveSubsystem() :
		Subsystem("DriveSubsystem")
{
	 RightMotor = new Victor(1);
	 LeftMotor = new Victor(0);

}

void DriveSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new OperatorDrive());
}

void DriveSubsystem::Drive(Joystick* right, Joystick* left)
{
	RightMotor->SetSpeed(right->GetY());
	LeftMotor->SetSpeed(left->GetY());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

