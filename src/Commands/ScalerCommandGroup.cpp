#include "ScalerCommandGroup.h"
//#include "IntakeOut.h"
#include "ScalerDeploy.h"
#include "ScalerRetract.h"
#include "ScalerScale.h"
#include "IntakeOut.h"
#include "WaitTrigger.h"


ScalerCommandGroup::ScalerCommandGroup() : CommandGroup()
{
	AddSequential(new IntakeOut());
	AddSequential(new ScalerDeploy());
	AddSequential(new ScalerRetract());
	AddSequential(new WaitTrigger(8));
	AddSequential(new ScalerScale());
}
