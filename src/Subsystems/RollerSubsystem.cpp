/**
 * RollerSubsystem is a class that keeps references to each of the
 * manipulators and sensors that are used by the intake roller.
 */

#include "RollerSubsystem.h"
#include "../RobotMap.h"

RollerSubsystem::RollerSubsystem() :
		Subsystem("RollerSubsystem")
{
	Roller = new Victor(ROLLER_MOTOR);
}

void RollerSubsystem::InitDefaultCommand()
{
	//SetDefaultCommand(new MySpecialCommand());
}

void RollerSubsystem::Roll(float power)
{
	Roller->SetSpeed(power);
}


