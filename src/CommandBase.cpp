#include "CommandBase.h"
#include "Commands/Scheduler.h"

#include <algorithm>

/**
 * CommandBase is a class that is the parent class to each of the commands used by the robot.
 * This allows the commands to access each subsystem.
 */

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<DriveSubsystem> CommandBase::drive;
std::unique_ptr<ShooterSubsystem> CommandBase::shooter;
std::unique_ptr<ExtentionSubsystem> CommandBase::extention;
// Empty constructors
CommandBase::CommandBase(const std::string &name) :
		Command(name)
{}

// Creates each subsystem, should only be run once!
void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	drive.reset(new DriveSubsystem());
	shooter.reset(new ShooterSubsystem());
	extention.reset(new ExtentionSubsystem());

	oi.reset(new OI());
}

// Print out some useful information about each subsystem
void CommandBase::prints() {
	shooter->prints();
	extention->print();
	SmartDashboard::PutNumber("drive.Gyro", drive->GetGyro());
	SmartDashboard::PutNumber("drive.encoder.ticks", drive->driveEncoder());

	int time_remaining = ceil(DriverStation::GetInstance().GetMatchTime() / 15.0);
	time_remaining = std::min(0, time_remaining - 3);
	SmartDashboard::PutNumber("Time to breach", time_remaining);
}
