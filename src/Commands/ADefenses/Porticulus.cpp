/**
 * Command that cycles through each state of the portculus aDefenses position. Immediately
 * exits after setting the setpoint.
 */

#include "Porticulus.h"

Porticulus::Porticulus() : CommandBase()
{
	Requires(aDefenses.get());
}

// Called just before this Command runs the first time
void Porticulus::Initialize()
{
	//Initializes the porticulus attachment by sequence(every time you click the button it goes to next setpoint)
	aDefenses->GoToNextPorticulusSetpoint(); // Change this line to initialize if doesn't work(delete this)
}

// Called repeatedly when this Command is scheduled to run
void Porticulus::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool Porticulus::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void Porticulus::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Porticulus::Interrupted()
{

}
