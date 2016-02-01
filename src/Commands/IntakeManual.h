#ifndef INTAKE_MANUAL_H
#define INTAKE_MANUAL_H

#include "../CommandBase.h"
#include "WPILib.h"

class IntakeManual: public CommandBase
{
private:

public:
	IntakeManual();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
