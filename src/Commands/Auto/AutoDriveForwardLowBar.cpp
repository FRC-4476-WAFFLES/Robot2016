/**
 * Drives forward under the low bar
 */

#include "AutoDriveForwardLowBar.h"
#include "Commands/Drive/DriveAuto.h"


AutoDriveForwardLowBar::AutoDriveForwardLowBar()
{
	SetTimeout(15.0);
	//todo: Adjust setpoint
	AddSequential(new DriveAuto(-9000.0, 0.0));
}
