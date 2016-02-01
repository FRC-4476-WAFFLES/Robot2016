#ifndef CAMERA_SUBSYSTEM_H
#define CAMERA_SUBSYSTEM_H

#include "WPILib.h"

class CameraSubsystem: public Subsystem
{
private:

	AxisCamera* Camera;


public:
	CameraSubsystem();
	void InitDefaultCommand();


};

#endif

