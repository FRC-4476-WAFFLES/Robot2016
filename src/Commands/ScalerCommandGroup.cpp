#include "ScalerCommandGroup.h"
//#include "IntakeOut.h"
#include "ScalerDeploy.h"
#include "ScalerScaleLong.h"
#include "IntakeOut.h"
//#include "WaitTrigger.h"
#include "ScalerStop.h"
#include "ScalerRelease.h"

ScalerCommandGroup::ScalerCommandGroup() : CommandGroup()
{
	AddSequential(new ScalerRelease());
	AddSequential(new IntakeOut());
	AddSequential(new ScalerDeploy());
	AddParallel(new IntakeOut());
	AddSequential(new ScalerScaleLong(-3498*1.05));
//	AddSequential(new WaitTrigger(8));
	AddSequential(new ScalerScaleLong(395));
	AddSequential(new ScalerStop());
}
