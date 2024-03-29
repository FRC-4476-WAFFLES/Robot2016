#ifndef ADEFENSES_SUBSYSTEM_H
#define ADEFENSES_SUBSYSTEM_H

#include "WPILib.h"
#include "CustomSensors/VexEncoder.h"

class ADefensesSubsystem: public PIDSubsystem
{
private:
	int PorticulusIndex;
	int ChevalDeFrisseIndex;
	Victor* Motor;
	VexEncoder* Potentiometer;
	
protected:
	double ReturnPIDInput();
	void UsePIDOutput(double);

public:
	ADefensesSubsystem();
	void InitDefaultCommand();
	void GoToNextPorticulusSetpoint();
	void move(float moveSpeed);
	void GoToNextChevalDeFrisseSetpoint();
	void GoToNextPorticulusSetpointAuto();
	void ADefensesReset();
};

#endif
