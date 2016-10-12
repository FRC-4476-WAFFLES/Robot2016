#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CustomSensors/VexEncoder.h"

class ShooterSubsystem: public Subsystem
{
private:
	Victor* pivot;
	Victor* top_shooter;
	Victor* bottom_shooter;
	Victor* top_roller;
	Victor* bottom_roller;
	Victor* extension;
	VexEncoder* pivot_e;
	VexEncoder* extension_e;
	DigitalInput* bottom_hardstop;
	Encoder* top_shooter_e;
	Encoder* bottom_shooter_e;
	PIDController* pivot_pid;
	PIDController* top_shooter_pid;
	PIDController* bottom_shooter_pid;
	PIDController* extension_pid;
public:
#warning "You didn't setup the numbers"
	static constexpr double shot_angle = 0.0;
	static constexpr double shot_speed = 0.0;
	static constexpr double extension_out = 0.0;
	static constexpr double roller_out = 0.0;
	static constexpr double roller_in = 0.0;

	ShooterSubsystem();
	void InitDefaultCommand();
	void PivotGotoAngle(double angle);
	bool PivotOnTarget();
	void SetRollers(double speed);
	void SetShooter(double speed);
	bool ShooterOnTarget();
	void SetExtension(double angle);
};