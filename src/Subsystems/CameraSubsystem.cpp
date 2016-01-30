#include "CameraSubsystem.h"
#include "../RobotMap.h"

CameraSubsystem::CameraSubsystem() :
		Subsystem("CameraSubsystem")
{
	Camera = new AxisCamera("axis-camera.local");

}

void CameraSubsystem::InitDefaultCommand()
{
	//SetDefaultCommand(new MySpecialCommand());

}




