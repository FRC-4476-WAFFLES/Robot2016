#include "Commands/AutoDoNothing.h"
//includes the .h file so we can use their variables
/*
 *
 * ------------
 *
 * DOES NOTHING
 * ************
 *
 * ------------
 */
AutoDoNothing::AutoDoNothing()
{
	//requires all the subsystems so they don`t run.
	Requires(aDefenses.get());
	Requires(scaler.get());
	Requires(roller.get());
	Requires(intake.get());
	Requires(drive.get());
}

// Called just before this Command runs the first time
void AutoDoNothing::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoDoNothing::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutoDoNothing::IsFinished()
{
	//stops the command
	return true;
}

// Called once after isFinished returns true
void AutoDoNothing::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDoNothing::Interrupted()
{

}
