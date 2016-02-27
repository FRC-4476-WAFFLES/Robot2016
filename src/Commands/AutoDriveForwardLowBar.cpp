#include <Commands/AutoDriveForwardLowBar.h>
// uses variables from the .h file

AutoDriveForwardLowBar::AutoDriveForwardLowBar()
{
	// uses all the subsystems so they don`t run
	Requires(aDefenses.get());
	Requires(scaler.get());
	Requires(roller.get());
	Requires(intake.get());
	Requires(drive.get());
	// gives the command 15 seconds to run.
	SetTimeout(15.0);
}

// Called just before this Command runs the first time
void AutoDriveForwardLowBar::Initialize()
{
	// resets the gyroscope to zero
	drive->resetGyro();
	// TODO: what needs to happen here?
	intake->Disable();
}

// Called repeatedly when this Command is scheduled to run
//1.0, 1.0 represents full speed (change accordingly)
void AutoDriveForwardLowBar::Execute()
{
	// sets the variable <gyroangle>
	float gyroAngle = drive->GetGyro();
	// makes the drive motor`s speed = half, plus
	drive->Drive(0.1*gyroAngle-0.5, -0.1*gyroAngle-0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveForwardLowBar::IsFinished()
{

	return drive->driveEncoder()>13188.;
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
