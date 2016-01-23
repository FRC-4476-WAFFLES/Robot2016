#ifndef SCALER_SUBSYSTEM_H
#define SCALER_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ScalerSubsystem: public Subsystem
{
private:
	Victor* ScalingMotor1;
	Victor* ScalingMotor2;
	Encoder* ScalingEncoder;
	Encoder* DeployingEncoder;
	Victor* DeployingVictor;
public:
	ScalerSubsystem();
	void InitDefaultCommand();
	void Drive (Joystick* right, Joystick* left);
};

#endif
