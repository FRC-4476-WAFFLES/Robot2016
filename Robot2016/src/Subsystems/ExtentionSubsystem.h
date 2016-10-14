#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CustomSensors/VexEncoder.h"

class ExtentionSubsystem: public Subsystem
{
private:

public:
	ExtentionSubsystem();
	void InitDefaultCommand();
	void PivotGotoAngle(double angle);
	bool PivotOnTarget();
	void SetRollers(double speed);
	void SetShooter(double speed);
	bool ShooterOnTarget();
	void SetExtension(double angle);
	void prints();
};
