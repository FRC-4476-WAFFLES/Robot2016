#ifndef INTAKE_OUT_NORMAL_H
#define INTAKE_OUT_NORMAL_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"
class IntakeOutNormal: public CommandBase
{
public:
	IntakeOutNormal();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
