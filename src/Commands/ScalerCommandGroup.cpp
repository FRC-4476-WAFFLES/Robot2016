#include "ScalerCommandGroup.h"
#include "ScalerDeploy.h"
#include "ScalerRetract.h"
#include "ScalerScale.h"
#include "IntakeOut.h"

ScalerCommandGroup::ScalerCommandGroup() : CommandGroup()
{
	AddSequential(new IntakeOut());
	AddSequential(new ScalerDeploy());
	AddSequential(new ScalerRetract());
	AddSequential(new ScalerScale());
}
