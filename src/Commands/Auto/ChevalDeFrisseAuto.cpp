
 #include "ChevalDeFrisseAuto.h"
#include "Commands/ADefenses/ChevalDeFrisse.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Misc/WaitTime.h"

ChevalDeFrisseAuto::ChevalDeFrisseAuto()
{
	SetTimeout(15.0);
		//todo: Adjust setpoint
	    AddSequential(new DriveAuto(3032.0, 0.0));
		AddSequential(new ChevalDeFrisse);


		AddSequential(new WaitTime(1));
		//todo: Adjust setpoint
		AddSequential(new DriveAuto (4070.0, 0.0));
		AddSequential(new ChevalDeFrisse);
		AddSequential(new WaitTime(2));
		//todo: Adjust setpoint
		AddSequential(new DriveAuto(5684.0, 0.0));
		AddParallel(new ChevalDeFrisse);
		AddSequential(new DriveAuto(13132.0, 0.0));
}
