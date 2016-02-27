/**
 * Drives forward under the low bar
 */

#include "AutoDriveForwardLowBar.h"
#include "Commands/Drive/DriveAuto.h"


AutoDriveForwardLowBar::AutoDriveForwardLowBar()
{
	SetTimeout(15.0);
	AddSequential(new DriveAuto(13188.0, 0.0));
}
