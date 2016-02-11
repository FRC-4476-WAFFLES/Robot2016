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
	Relay* PositionLock;
public:
	ScalerSubsystem();
	void InitDefaultCommand();
	double GetDeploy();
	void SetDeploy(double Speed);
	void ScalingMotors(double Speed);
	double ScaleEncoder();

};

#endif
