#ifndef PORTICULUS_H
#define PORTICULUS_H

#include "CommandBase.h"
#include "WPILib.h"
#include "Subsystems/ADefensesSubsystem.h"

class Porticulus: public CommandBase
{
public:
	Porticulus();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
