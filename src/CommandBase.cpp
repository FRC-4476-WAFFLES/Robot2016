#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<DriveSubsystem> CommandBase::drive;
std::unique_ptr<IntakeSubsystem> CommandBase::intake;
std::unique_ptr<RollerSubsystem> CommandBase::roller;
std::unique_ptr<ADefensesSubsystem> CommandBase::GoToAngle;
CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	intake.reset(new IntakeSubsystem());
	drive.reset(new DriveSubsystem());
	oi.reset(new OI());
	roller.reset(new RollerSubsystem());
	GoToAngle.reset(new ADefensesSubsystem());
}
