#ifndef AUTO_DRIVE_FORWARD_H
#define AUTO_DRIVE_FORWARD_H

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
