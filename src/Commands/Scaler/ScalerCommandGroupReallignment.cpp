#include "ScalerCommandGroupReallignment.h"
#include "ScalerUndeploy.h"
#include "ScalerScaleLong.h"
#include "Commands/Intake/IntakeOut.h"
#include "Commands/Misc/WaitTrigger.h"
#include "ScalerStop.h"
#include "ScalerRelease.h"

/**
 * Extends the climber up and begins to climb after a button is pressed.
 */

ScalerCommandGroupReallignment::ScalerCommandGroupReallignment() : CommandGroup()
{
	AddSequential(new ScalerScaleLong(-3498*1.05));
	AddSequential(new WaitTrigger(new JoystickButton(CommandBase::oi->operatorController, CommandBase::oi->BumperBottomRight)));
	AddSequential(new ScalerScaleLong(395));
	AddSequential(new ScalerStop());
}
