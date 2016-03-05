/**
 * Drives forward under the low bar
 */

#include "AutoScore.h"
#include "Commands/Drive/DriveAuto.h"
#include "AutoDriveForwardLowBar.h"
#include "Commands/Intake/IntakeOut.h"
#include "Commands/Roller/RollerExtract.h"

AutoScore::AutoScore()
{
	SetTimeout(15.0);
	AddSequential(new IntakeOut);
	AddSequential(new DriveAuto(13188.0, 0.0));
	//todo: Adjust setpoint
	AddSequential(new DriveAuto(13188.0,136.5));
	//todo: Adjust setpoint
	AddSequential(new DriveAuto(25681.9,136.5));
	AddSequential(new RollerExtract);
}
