#include "AutoScore.h"
#include "Commands/Drive/DriveAuto.h"
#include "AutoDriveForwardLowBar.h"
#include "Commands/Intake/IntakeOut.h"
#include "Commands/Roller/RollerExtract.h"
#include "Commands/Intake/IntakeOutNormal.h"
#include "Commands/Intake/IntakeOutAuto.h"
AutoScore::AutoScore()
{
//	SetTimeout(15.0);
//	AddSequential(new IntakeOutAuto);
//	AddSequential(new DriveAuto(-17287.0, 0.0));
//	//todo: Adjust setpoint
//	Wait(1.0);
//	AddSequential(new DriveAuto(-17287.0,60.0));
//	//todo: Adjust setpoint
//	Wait(1.0);
//	AddSequential(new DriveAuto(-27123.9,60.0));
//	AddSequential(new RollerExtract);

	AddSequential(new IntakeOutAuto);
	AddSequential(new DriveAuto(-500.0, 0.0));
	//todo: Adjust setpoint
	Wait(1.0);
	AddSequential(new DriveAuto(-500.0,60.0));
	//todo: Adjust setpoint
	Wait(1.0);
	AddSequential(new DriveAuto(-1000.9,60.0));
	AddSequential(new RollerExtract);
}
