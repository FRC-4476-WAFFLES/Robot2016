#include "ScalerCommandGroup.h"
//#include "IntakeOut.h"
#include "ScalerDeploy.h"
#include "scalerRetract.h"
#include "ScalerScale.h"



ScalerCommandGroup::ScalerCommandGroup() : CommandGroup()
{
	//AddSequential(new IntakeOut());
	AddSequential(new ScalerDeploy());
	AddSequential(new ScalerRetract());
	AddSequential(new ScalerScale());
}

