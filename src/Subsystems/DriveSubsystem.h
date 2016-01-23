#ifndef DRIVE_SUBSYSTEM_H
#define DRIVE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveSubsystem: public Subsystem
{
private:
	Victor* RightMotorFront;
	Victor* LeftMotorFront;
	Victor* RightMotorBack;
	Victor*LeftMotorBack;
public:
	DriveSubsystem();
	void InitDefaultCommand();
	void Drive (Joystick* right, Joystick* left);
};

#endif
