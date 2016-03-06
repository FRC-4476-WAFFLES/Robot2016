#include "AutoDriveReverse.h"
#include "Commands/Drive/DriveAuto.h"


AutoDriveReverse::AutoDriveReverse()
{
	SetTimeout(15.0);

	AddSequential(new DriveAuto(-13188.0, 0.0));
	AddSequential(new DriveAuto(0.0, 0.0));
}
