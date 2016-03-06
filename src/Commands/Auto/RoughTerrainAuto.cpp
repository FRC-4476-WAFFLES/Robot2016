/**
 * Drives forward under the low bar
 */

#include "RoughTerrainAuto.h"
#include "Commands/Drive/DriveAuto.h"


RoughTerrainAuto::RoughTerrainAuto()
{

	//SetTimeout(15.0);
	AddSequential(new DriveAuto(-9000.0, 0.0));
}
