#ifndef OPERATOR_DRIVE_H
#define OPERATOR_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"

class OperatorDrive: public CommandBase
{
public:
	OperatorDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
