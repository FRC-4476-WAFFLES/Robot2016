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
	//No default command
}

// Sets the speed of the intake roller motor.
void RollerSubsystem::Roll(float power)
{
	Roller->SetSpeed(power);
}


