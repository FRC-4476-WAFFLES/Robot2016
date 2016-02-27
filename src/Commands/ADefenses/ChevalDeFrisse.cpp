#include "ChevalDeFrisse.h"
// makes the a defenses mechanism work for the cheval de frisse

// needs the undivided attention of ADefenses
ChevalDeFrisse::ChevalDeFrisse() : CommandBase()
{
	Requires(aDefenses.get());

}

// Called just before this Command runs the first time
// goes to the next set point for cheval de frisse when the button is pressed
void ChevalDeFrisse::Initialize()
{
	//Initiates the ChevalDeFrisse setpoints everytime the button is pressed
	aDefenses->GoToNextChevalDeFrisseSetpoint();
}

// Called repeatedly when this Command is scheduled to run
void ChevalDeFrisse::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
// stops the command
bool ChevalDeFrisse::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ChevalDeFrisse::End()
{

}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChevalDeFrisse::Interrupted()
{

}
