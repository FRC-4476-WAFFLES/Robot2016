#ifndef ROLLER_SUCK_H
#define ROLLER_SUCK_H

#include "CommandBase.h"
#include "WPILib.h"

class RollerSuck: public CommandBase
{
public:
	RollerSuck();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
