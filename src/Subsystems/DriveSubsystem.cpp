#include "DriveSubsystem.h"
#include "../RobotMap.h"
#include "Commands/OperatorDrive.h"

DriveSubsystem::DriveSubsystem():
		Subsystem("DriveSubsystem")
{
	 RightMotorFront = new Victor(DRIVE_MOTOR_RIGHT_FRONT);
	 RightMotorBack = new  Victor(DRIVE_MOTOR_RIGHT_BACK);
	 LeftMotorFront = new Victor(DRIVE_MOTOR_LEFT_FRONT);
	 LeftMotorBack = new Victor(DRIVE_MOTOR_LEFT_BACK);
}

void DriveSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new OperatorDrive());

}

void DriveSubsystem::Drive(double left, double right)
{
	RightMotorFront->SetSpeed(right);
	LeftMotorFront->SetSpeed(-left);
	RightMotorBack->SetSpeed(right);
	LeftMotorBack->SetSpeed(-left);
}
