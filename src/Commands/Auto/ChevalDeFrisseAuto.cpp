
 #include "ChevalDeFrisseAuto.h"
#include "Commands/ADefenses/ChevalDeFrisse.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Misc/WaitTime.h"

ChevalDeFrisseAuto::ChevalDeFrisseAuto()
{
	SetTimeout(15.0);
		//todo: Adjust setpoint
	    AddSequential(new DriveAuto(-5100.0, 0.0));
		AddSequential(new ChevalDeFrisse);
		AddSequential(new WaitTime(1));
		//todo: Adjust setpoint
		AddSequential(new DriveAuto (-6000.0, 0.0));
		AddSequential(new ChevalDeFrisse);
		AddSequential(new WaitTime(2));
		//todo: Adjust setpoint
		AddSequential(new DriveAuto(-7500.0, 0.0));
		AddSequential(new ChevalDeFrisse);
}
