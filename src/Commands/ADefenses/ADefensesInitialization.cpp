/**
 * Command that cycles through each state of the portculus aDefenses position. Immediately
 * exits after setting the setpoint.
 */

#include "ADefensesInitialization.h"


ADefensesInitialization::ADefensesInitialization() : CommandBase()
{
}

// Called just before this Command runs the first time
void ADefensesInitialization::Initialize()
{
	//Initializes the ADefensesInitialization attachment by sequence(every time you click the button it goes to next setpoint)
//	switch((int) oi->ADefensesChooser->GetSelected()) {
//	case 0:
//		aDefenses->GoToNextChevalDeFrisseSetpoint();
//		break;
//	case 1:
//		aDefenses->GoToNextPorticulusSetpoint();
//		break;

//	}
}

// Called repeatedly when this Command is scheduled to run
void ADefensesInitialization::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool ADefensesInitialization::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ADefensesInitialization::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ADefensesInitialization::Interrupted()
{

}
