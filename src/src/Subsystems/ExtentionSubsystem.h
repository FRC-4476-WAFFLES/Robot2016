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
};
