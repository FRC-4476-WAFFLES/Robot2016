#include "ScalerCommandGroupUndeploy.h"
//#include "IntakeOut.h"
#include "ScalerUndeploy.h"
#include "ScalerScaleLong.h"
#include "IntakeOut.h"
//#include "WaitTrigger.h"
#include "ScalerStop.h"
#include "ScalerRelease.h"


ScalerCommandGroupReallignment::ScalerCommandGroupReallignment() : CommandGroup()
{
	AddSequential(new ScalerScaleLong(-3498*1.05));
//	AddSequential(new WaitTrigger(8));
	AddSequential(new ScalerScaleLong(395));

}
