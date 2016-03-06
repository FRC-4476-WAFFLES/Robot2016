#ifndef INTAKE_OUT_AUTO_H
#define INTAKE_OUT_AUTO_H

#include "CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"

class IntakeOutAuto: public CommandBase
{
public:
	IntakeOutAuto();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
