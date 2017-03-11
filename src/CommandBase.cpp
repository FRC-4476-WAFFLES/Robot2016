#include "CommandBase.h"
#include "Commands/Scheduler.h"

/**
 * CommandBase is a class that is the parent class to each of the commands used by the robot.
 * This allows the commands to access each subsystem.
 */

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<DriveSubsystem> CommandBase::drive;
std::unique_ptr<IntakeSubsystem> CommandBase::intake;
std::unique_ptr<RollerSubsystem> CommandBase::roller;
std::unique_ptr<ADefensesSubsystem> CommandBase::aDefenses;
std::unique_ptr<ScalerSubsystem> CommandBase::scaler;

// Empty constructors
CommandBase::CommandBase(const std::string &name) :
		Command(name)
{}

CommandBase::CommandBase() :
		Command()
{}

// Creates each subsystem, should only be run once!
void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	intake.reset(new IntakeSubsystem());
	drive.reset(new DriveSubsystem());
	roller.reset(new RollerSubsystem());
	aDefenses.reset(new ADefensesSubsystem());
	scaler.reset(new ScalerSubsystem());

	oi.reset(new OI());
}

// Print out some useful information about each subsystem
void CommandBase::prints() {
	SmartDashboard::PutNumber("aDefenses.Angle", aDefenses->GetPosition());
	SmartDashboard::PutNumber("scaler.Scaler.Ticks", scaler->ScaleEncoder());
	SmartDashboard::PutNumber("scaler.Deploy.Angle", scaler->GetDeploy());
	SmartDashboard::PutNumber("intake.Angle", intake->GetPosition());
	SmartDashboard::PutNumber("intake.CorrectPosition", intake->GetSetpoint());
	SmartDashboard::PutNumber("intake.Position" ,intake->GetPosition());
	SmartDashboard::PutNumber("drive.Gyro", drive->GetGyro());
	SmartDashboard::PutNumber("drive.encoder.ticks", drive->driveEncoder());
	SmartDashboard::PutNumber("SonarSensor inches", drive->SonarSensor->GetVoltage()*1000/0.977/25.4);
	SmartDashboard::PutNumber("SonarSensor voltage", drive->SonarSensor->GetVoltage());
}
