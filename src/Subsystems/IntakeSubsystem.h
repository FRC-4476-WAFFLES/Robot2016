#ifndef INTAKE_SUBSYSTEM_H
#define INTAKE_SUBSYSTEM_H
#include "CustomSensors/VexEncoder.h"
#include "WPILib.h"

class IntakeSubsystem: public PIDSubsystem
{
private:
	Victor* Arm;
	DigitalInput* IntakeRetracted;
	VexEncoder* IntakeAngle;
protected:
	double ReturnPIDInput();
	void UsePIDOutput(double);
public:
	IntakeSubsystem();
	void InitDefaultCommand();
	void Out();
    void In();
    void Move(float moveSpeed);


};

#endif

