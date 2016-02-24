#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<DriveSubsystem> CommandBase::drive;
std::unique_ptr<IntakeSubsystem> CommandBase::intake;
std::unique_ptr<RollerSubsystem> CommandBase::roller;
std::unique_ptr<ADefensesSubsystem> CommandBase::aDefenses;
std::unique_ptr<ScalerSubsystem> CommandBase::scaler;

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
	roller.reset(new RollerSubsystem());
	aDefenses.reset(new ADefensesSubsystem());
	scaler.reset(new ScalerSubsystem());

	oi.reset(new OI());
}

void CommandBase::prints() {
	SmartDashboard::PutNumber("aDefenses.Angle", aDefenses->GetPosition());
	SmartDashboard::PutNumber("scaler.Scaler.Ticks", scaler->ScaleEncoder());
	SmartDashboard::PutNumber("scaler.Deploy.Angle", scaler->GetDeploy());
	SmartDashboard::PutNumber("intake.Angle", intake->GetPosition());
	SmartDashboard::PutNumber("intake.CorrectPosition", intake->GetSetpoint());
	SmartDashboard::PutNumber("intake.Position" ,intake->GetPosition());
	SmartDashboard::PutNumber("drive.Gyro", drive->GetGyro());
	SmartDashboard::PutNumber("drive.encoder.ticks", drive->driveEncoder());
}
