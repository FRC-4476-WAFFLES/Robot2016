#ifndef ADEFENSES_SUBSYSTEM_H
#define ADEFENSES_SUBSYSTEM_H

#include "WPILib.h"
#include "CustomSensors/VexEncoder.h"
class ADefensesSubsystem: public PIDSubsystem
{
private:
	int PorticulusIndex;
		Victor* Motor;
		VexEncoder* Potentiometer;
protected:
	double ReturnPIDInput();
	void UsePIDOutput(double);

public:
	ADefensesSubsystem();
	void InitDefaultCommand();
	float rawAngle;
	void GoToNextPorticulusSetpoint();
	void move(float moveSpeed);


};

#endif

