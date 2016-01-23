#ifndef INTAKE_SUBSYSTEM_H
#define INTAKE_SUBSYSTEM_H

#include "WPILib.h"

class IntakeSubsystem: public PIDSubsystem
{
private:
	Victor* Arm;
	Victor* Roller;

	DigitalInput* IntakeRetracted;
	Encoder* IntakeAngle;
protected:
	double ReturnPIDInput();
	void UsePIDOutput(double);
public:
	IntakeSubsystem();
	void InitDefaultCommand();
	void Out();
    void In();
    void Roll(float power);

};

#endif

