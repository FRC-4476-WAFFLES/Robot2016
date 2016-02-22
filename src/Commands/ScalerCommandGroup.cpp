#include "ScalerCommandGroup.h"
#include "ScalerDeploy.h"
#include "scalerRetract.h"
#include "ScalerScale.h"


ScalerCommandGroup::ScalerCommandGroup() : CommandGroup()
{
	AddSequential(new ScalerDeploy());
	AddSequential(new ScalerRetract());
	AddSequential(new ScalerScale());
}

