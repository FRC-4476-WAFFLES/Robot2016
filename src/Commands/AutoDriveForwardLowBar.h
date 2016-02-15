#ifndef AUTO_DRIVE_FORWARD_LOW_BAR_H
#define AUTO_DRIVE_FORWARD_LOW_BAR_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoDriveForwardLowBar: public CommandBase
{
public:
	AutoDriveForwardLowBar();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif
