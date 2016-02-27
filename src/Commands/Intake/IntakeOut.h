#ifndef INTAKE_OUT_H
#define INTAKE_OUT_H

#include "CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"

class IntakeOut: public CommandBase
{
public:
	IntakeOut();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
