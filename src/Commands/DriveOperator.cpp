#include <Commands/DriveOperator.h>

DriveOperator::DriveOperator()
{
	Requires(drive.get());
}

// Called just before this Command runs the first time
void DriveOperator::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveOperator::Execute()
{
	//drive->Drive(oi.get()->joystickLeft, oi.get()->joystickRight);

	double controllerLeft = oi.get()->joystickLeft->GetY(); //+ oi.get()->operatorController->GetRawAxis(1) / 3.7;
	double controllerRight = oi.get()->joystickRight->GetY(); // + oi.get()->operatorController->GetRawAxis(3) / 3.7;
	drive->Drive(controllerLeft, controllerRight);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveOperator::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveOperator::End()
{
	drive->Drive(0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveOperator::Interrupted()
{
	drive->Drive(0.0, 0.0);
}