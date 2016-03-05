/*
 * ChooserDispatch runs the aDefenses command that is selected
 */

#include <Commands/ADefenses/ChooserDispatch.h>

ChooserDispatch::ChooserDispatch() {

}

// Called just before this Command runs the first time
void ChooserDispatch::Initialize()
{
	Command* chevalCommand = (Command*) oi.get()->aDefensesChooser->GetSelected();
	chevalCommand->Start();
}

// Called repeatedly when this Command is scheduled to run
void ChooserDispatch::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool ChooserDispatch::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ChooserDispatch::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChooserDispatch::Interrupted()
{

}

