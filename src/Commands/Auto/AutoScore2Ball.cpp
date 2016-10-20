#include "AutoScore2Ball.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Auto/ShootAuto.h"
#include "Commands/Auto/OuttakeShootAuto.h"
#include "Commands/Auto/IntakeAuto.h"
#include "Commands/Shooter/Intake.h"
#include "Commands/Shooter/ShooterUp.h"
#include "Commands/Shooter/ExtentionOut.h"

AutoScore2Ball::AutoScore2Ball()
{
	SetTimeout(15.0);
	AddSequential(new DriveAuto(17817.0, 0.0));
	AddSequential(new OuttakeShootAuto());
	AddSequential(new DriveAuto(100.0, 0.0));
	Scheduler::GetInstance()->AddCommand(new IntakeAuto());
	AddSequential(new DriveAuto(0.0, 0.0));
	Scheduler::GetInstance()->AddCommand(new ShooterUp());
	AddSequential(new DriveAuto(17817.0, 0.0));
	AddSequential(new OuttakeShootAuto());
	AddSequential(new DriveAuto(0.0, 0.0));
}
