#ifndef ADEFENSES_SUBSYSTEM_H
#define ADEFENSES_SUBSYSTEM_H

#include "WPILib.h"

class ADefensesSubsystem: public PIDSubsystem
{
private:

		Victor* Motor;
		AnalogPotentiometer* Potentiometer;
protected:
	double ReturnPIDInput();
	void UsePIDOutput(double);
public:
	ADefensesSubsystem();
	void InitDefaultCommand();


};

#endif

