#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CustomSensors/NonLoopingVexEncoder.h"
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
	Relay* flashlight;
	VexEncoder* pivot_e;
	NonLoopingVexEncoder* extension_e;
	//DigitalInput* bottom_hardstop;
	Encoder* top_shooter_e;
	Encoder* bottom_shooter_e;
	PIDController* pivot_pid;
	PIDController* top_shooter_pid;
	PIDController* bottom_shooter_pid;
	PIDController* extension_pid;
public:
	static constexpr double shot_angle = -24.0;
	static constexpr double intake_angle = 298.0;
	static constexpr double shot_speed = -40.0;
	static constexpr double shooter_intake_speed = 10.0;
	static constexpr double roller_in = 0.3;
	static constexpr double roller_out = -0.3;
	static constexpr double extention_in = 41.0;
	static constexpr double extention_out = 214.0;


	ShooterSubsystem();
	void InitDefaultCommand();
	void PivotGotoAngle(double angle);
	bool PivotOnTarget();
	void SetRollers(double speed);
	void SetShooter(double speed);
	void SetShooterWithoutTarget(double speed);
	bool ShooterOnTarget();
	double DeltaSpeed();
	void SetExtension(double angle);
	void SetFlashlight(bool on);
	void ManualControl(bool flashlight, double extension, double speed, double pivot, float roller_speed);
	void prints();
};
