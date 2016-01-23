#ifndef ROLLER_EXTRACT_H
#define ROLLER_EXTRACT_H

#include "../CommandBase.h"
#include "WPILib.h"

class RollerExtract: public CommandBase
{
public:
	RollerExtract();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
