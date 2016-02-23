#include <Commands/DriveOperator.h>
#include "DriveSubsystem.h"
#include "../RobotMap.h"

DriveSubsystem::DriveSubsystem():
		Subsystem("DriveSubsystem")
{
	 RightMotorFront = new Victor(DRIVE_MOTOR_RIGHT_FRONT);
	 RightMotorBack = new  Victor(DRIVE_MOTOR_RIGHT_BACK);
	 LeftMotorFront = new Victor(DRIVE_MOTOR_LEFT_FRONT);
	 LeftMotorBack = new Victor(DRIVE_MOTOR_LEFT_BACK);
	 gyro = new ADXRS450_Gyro();
}

void DriveSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveOperator());
}

double DriveSubsystem::GetGyro() {
	return gyro->GetAngle();
}

void DriveSubsystem::resetGyro(){
	gyro->Reset();
}
void DriveSubsystem::Drive(double left, double right)
{
	RightMotorFront->SetSpeed(right);
	LeftMotorFront->SetSpeed(-left);
	RightMotorBack->SetSpeed(right);
	LeftMotorBack->SetSpeed(-left);
}
