#include "Porticulus.h"



Porticulus::Porticulus() : CommandBase()
{
	Requires(aDefenses.get());
}

// Called just before this Command runs the first time
//422.381,193
void Porticulus::Initialize()
{
	// If this does not work in Initialize constructor, add it to Execute for a trial *delete this comment after*
	//Cases only work for int and char
	//aDefenses->GoToNextPorticulusSetpoint();

}

// Called repeatedly when this Command is scheduled to run
void Porticulus::Execute()
{

	aDefenses->GoToNextPorticulusSetpoint(); // Change this line to initialize if doesn't work(delete this)
	float speed = oi.get()->operatorController->GetZ();
	aDefenses.get()->move(speed);
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
