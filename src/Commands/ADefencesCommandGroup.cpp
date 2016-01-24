#include "ADefensesCommandGroup.h"
#include "ADefensesGoToAngle.h"


ADefensesCommandGroup::ADefensesCommandGroup() : CommandGroup()
{

	AddSequential(new ADefensesGoToAngle(90));


}

// Called just before this Command runs the first time
void ADefensesCommandGroup::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ADefensesCommandGroup::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool ADefensesCommandGroup::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ADefensesCommandGroup::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ADefensesCommandGroup::Interrupted()
{

}
