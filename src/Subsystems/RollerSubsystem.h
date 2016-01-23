#ifndef ROLLER_SUBSYSTEM_H
#define ROLLER_SUBSYSTEM_H

#include "WPILib.h"

class RollerSubsystem: public Subsystem
{
private:

	Victor* Roller;

public:
	RollerSubsystem();
	void InitDefaultCommand();
    void Roll(float power);

};

#endif

