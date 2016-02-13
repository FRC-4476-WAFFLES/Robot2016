#include <Commands/AutoDriveForwardLowBar.h>

AutoDriveForward::AutoDriveForward()
{
	SetTimeout(5.0);
}

// Called just before this Command runs the first time
void AutoDriveForward::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
//1.0, 1.0 represents full speed (change accordingly)
void AutoDriveForward::Execute()
{
	drive->Drive(0.5, 0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveForward::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoDriveForward::End()
{
	drive->Drive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveForward::Interrupted()
{
	drive->Drive(0.0, 0.0);
}
