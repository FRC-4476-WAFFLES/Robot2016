#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Subsystems/IntakeSubsystem.h"
#include "Subsystems/DriveSubsystem.h"
#include "OI.h"
#include "WPILib.h"
#include "Subsystems/RollerSubsystem.h"
#include "Subsystems/ADefensesSubsystem.h"
#include "Subsystems/ScalerSubsystem.h"
//#include "subsystems/CameraSubsystem.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(const std::string &name);
	CommandBase();
	static void init();
	static void prints();
	// Create a single static instance of all of your subsystems
	static std::unique_ptr<IntakeSubsystem> intake;
	static std::unique_ptr<DriveSubsystem> drive;
	static std::unique_ptr<RollerSubsystem> roller;
	static std::unique_ptr<ADefensesSubsystem> aDefenses;
	static std::unique_ptr<ScalerSubsystem> scaler;
	static std::unique_ptr<OI> oi;
	//static std::unique_ptr<CameraSubsystem> camera;
};

#endif
