#ifndef AUTO_DO_NOTHING_H
#define AUTO_DO_NOTHING_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoDriveForward: public CommandBase
{
public:
	AutoDriveForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
