#include "ScalerCommandGroup.h"
#include "ScalerCommandGroupReallignment.h"
#include "ScalerDeploy.h"
#include "ScalerScaleLong.h"
#include "Commands/Intake/IntakeOut.h"
#include "ScalerRelease.h"

/**
 * Moves the scaler into a position for climbing
 */

ScalerCommandGroup::ScalerCommandGroup() : CommandGroup()
{
	AddSequential(new ScalerRelease());
	AddSequential(new IntakeOut());
	AddSequential(new ScalerDeploy());
	AddParallel(new IntakeOut());
	AddSequential(new ScalerCommandGroupReallignment());
}
