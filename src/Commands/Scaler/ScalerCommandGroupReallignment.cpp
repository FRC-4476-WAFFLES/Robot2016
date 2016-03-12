#include "ScalerCommandGroupReallignment.h"
#include "ScalerUndeploy.h"
#include "ScalerScaleLong.h"
#include "Commands/Intake/IntakeOut.h"
#include "Commands/Misc/WaitTrigger.h"
#include "ScalerDeploy.h"
#include "ScalerStop.h"
#include "ScalerRelease.h"

/**
 * Extends the climber up and begins to climb after a button is pressed.
 */

ScalerCommandGroupReallignment::ScalerCommandGroupReallignment() : CommandGroup()
{
	AddSequential(new ScalerRelease());
	AddSequential(new IntakeOut());
	AddSequential(new ScalerDeploy());
	AddSequential(new ScalerScaleLong(-3498*1.05));
	AddSequential(new WaitTrigger());
	AddSequential(new ScalerScaleLong(295));
	AddSequential(new ScalerStop());
}
