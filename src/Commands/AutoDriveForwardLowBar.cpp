#include <Commands/AutoDriveForwardLowBar.h>

AutoDriveForwardLowBar::AutoDriveForwardLowBar()
{
	SetTimeout(5.0);
}

// Called just before this Command runs the first time
void AutoDriveForwardLowBar::Initialize()
{
	drive->resetGyro();
}

// Called repeatedly when this Command is scheduled to run
//1.0, 1.0 represents full speed (change accordingly)
void AutoDriveForwardLowBar::Execute()
{

	float gyroAngle = drive->GetGyro();

	drive->Drive(-0.1*gyroAngle+0.0, 0.1*gyroAngle+0.0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveForwardLowBar::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoDriveForwardLowBar::End()
{
	drive->Drive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveForwardLowBar::Interrupted()
{
	drive->Drive(0.0, 0.0);
}
