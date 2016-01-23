#include "RollerSubsystem.h"
#include "../RobotMap.h"

RollerSubsystem::RollerSubsystem() :
		Subsystem("RollerSubsystem")
{

	Roller = new Victor(5);

}

void RollerSubsystem::InitDefaultCommand()
{
	//SetDefaultCommand(new MySpecialCommand());
}

void RollerSubsystem::Roll(float power)
{
	Roller->SetSpeed(power);
}


