#include "ScalerCommandGroupUndeploy.h"
//#include "IntakeOut.h"
#include "ScalerUndeploy.h"
#include "ScalerScaleLong.h"
#include "IntakeOut.h"
//#include "WaitTrigger.h"
#include "ScalerStop.h"
#include "ScalerRelease.h"


ScalerCommandGroupUndeploy::ScalerCommandGroupUndeploy() : CommandGroup()
{
	AddSequential(new ScalerRelease());
	AddSequential(new IntakeOut());
	AddSequential(new ScalerScaleLong(0));
	AddParallel(new IntakeOut());
	AddSequential(new ScalerUndeploy());
	AddParallel(new IntakeOut());
//	AddSequential(new WaitTrigger(8));
}
