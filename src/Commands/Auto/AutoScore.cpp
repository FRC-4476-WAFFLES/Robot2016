#include "AutoScore.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Auto/ShootAuto.h"
#include "Commands/Shooter/Intake.h"
#include "Commands/Shooter/ExtentionOut.h"
AutoScore::AutoScore()
{
	SetTimeout(15.0);
	Scheduler::GetInstance()->AddCommand(new Intake());
	AddSequential(new DriveAuto(17817.0, 0.0));
	AddSequential(new WaitTime(1.0));
	AddSequential(new DriveAuto(19817.0,60.0));
	AddSequential(new WaitTime(1.0));
	AddSequential(new DriveAuto(27653.9,60.0));
	Scheduler::GetInstance()->AddCommand(new ExtentionOut());
	AddSequential(new ShootAuto());
	AddSequential(new WaitTime(1.0));
	AddSequential(new DriveAuto(19817.0,90.0));
	AddSequential(new WaitTime(1.0));
	AddSequential(new DriveAuto(19817.0,-20.0));
	AddSequential(new WaitTime(1.0));
	AddSequential(new DriveAuto(19817.0,60.0));
}
