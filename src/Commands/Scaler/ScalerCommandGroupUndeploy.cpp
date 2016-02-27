#include "ScalerCommandGroupUndeploy.h"
#include "ScalerUndeploy.h"
#include "ScalerScaleLong.h"
#include "Commands/Intake/IntakeOut.h"
#include "ScalerRelease.h"

/**
 * Retracts the scaler and folds it into the robot.
 */

ScalerCommandGroupUndeploy::ScalerCommandGroupUndeploy() : CommandGroup()
{
	AddSequential(new ScalerRelease());
	AddSequential(new IntakeOut());
	AddSequential(new ScalerScaleLong(0));
	AddSequential(new ScalerUndeploy());
}
