#ifndef DRIVE_SUBSYSTEM_H
#define DRIVE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveSubsystem: public Subsystem
{
private:
	Victor* RightMotor; Victor* LeftMotor;
public:
	DriveSubsystem();
	void InitDefaultCommand();
	void Drive (Joystick* right, Joystick* left);
};

#endif
