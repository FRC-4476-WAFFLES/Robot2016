#ifndef INTAKE_IN_H
#define INTAKE_IN_H

#include "CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"
class IntakeIn: public CommandBase
{
public:
	IntakeIn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
