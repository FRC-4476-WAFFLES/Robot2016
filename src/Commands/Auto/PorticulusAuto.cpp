#include "PorticulusAuto.h"
#include "Commands/ADefenses/Porticulus.h"
#include "Commands/Drive/DriveAuto.h"
#include "Commands/Misc/WaitTime.h"

PorticulusAuto::PorticulusAuto()
{
	SetTimeout(15.0);
	//todo: Adjust setpoint
	AddSequential(new DriveAuto(3032.0, 0.0));
	AddSequential(new Porticulus);
	AddSequential(new Porticulus);


	Wait(1);
	//todo: Adjust setpoint
	AddSequential(new DriveAuto (13132.0, 0.0));
	AddSequential(new Porticulus);

	AddSequential(new WaitTime(2));
	//todo: Adjust setpoint

}
