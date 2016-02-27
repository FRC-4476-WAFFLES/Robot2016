#include "ChevalDeFrisse.h"



ChevalDeFrisse::ChevalDeFrisse() : CommandBase()
{
	Requires(aDefenses.get());

}

// Called just before this Command runs the first time
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
