#include "AutoScore.h"
#include "Commands/Misc/WaitTime.h"
#include "Commands/Drive/DriveAuto.h"
#include "AutoDriveForwardLowBar.h"
#include "Commands/Intake/IntakeOut.h"
#include "Commands/Roller/RollerExtract.h"
#include "Commands/Intake/IntakeOutNormal.h"
#include "Commands/Intake/IntakeOutAuto.h"
#include "Commands/Roller/RollerSuck.h"
#include "Commands/Drive/DriveRollerExtract.h"
#include "Commands/Roller/RollerSuckTime.h"

AutoScore::AutoScore()
{
	SetTimeout(15.0);
	AddSequential(new IntakeOutAuto);
	AddParallel(new RollerSuckTime(1.0));
	AddSequential(new DriveAuto(-17287.0, 0.0));
	AddSequential(new WaitTime(1.0));
	AddSequential(new DriveAuto(-19287.0,60.0));
	AddSequential(new WaitTime(1.0));
	AddSequential(new DriveAuto(-27123.9,60.0));
	AddSequential(new DriveRollerExtract);


}
