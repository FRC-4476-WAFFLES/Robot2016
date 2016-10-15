/**
 * ExtentionSubsystem is a class that keeps references to each of the
 * motors and provides low-level ways of interacting with the shooter mechanism
 * that can be used by the commands.
 */

#include "ExtentionSubsystem.h"
#include "../RobotMap.h"
#include "Commands/Shooter/Shoot.h"

ExtentionSubsystem::ExtentionSubsystem():
  Subsystem("ExtentionSubsystem"){

}

void ExtentionSubsystem::InitDefaultCommand()
{

}
