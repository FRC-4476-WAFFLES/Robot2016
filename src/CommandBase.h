#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Subsystems/IntakeSubsystem.h"
#include "Subsystems/DriveSubsystem.h"
#include "OI.h"
#include "WPILib.h"

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
	// Create a single static instance of all of your subsystems
	static std::unique_ptr<IntakeSubsystem> intake;
	static std::unique_ptr<DriveSubsystem> drive;
	static std::unique_ptr<OI> oi;
};

#endif
