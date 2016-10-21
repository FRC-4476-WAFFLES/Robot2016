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
	AddSequential(new DriveAuto(13439.0, 0.0, 0.7));
	AddSequential(new OuttakeShootAuto());
	AddSequential(new DriveAuto(6748.0, 0.0, 0.7));
	AddParallel(new IntakeAuto());
	AddSequential(new DriveAuto(-100.0, 0.0, 0.7));
	AddParallel(new ShooterUp());
	AddSequential(new DriveAuto(13439.0, 0.0, 0.7));
	AddSequential(new OuttakeShootAuto());
	AddSequential(new DriveAuto(0.0, 0.0));
}
