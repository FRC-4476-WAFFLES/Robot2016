#ifndef A_DEFENSES_INITIALIZATION_H
#define A_DEFENSES_INITIALIZATION_H

#include "CommandBase.h"
#include "WPILib.h"
#include "Subsystems/ADefensesSubsystem.h"

class ADefensesInitialization: public CommandBase
{
public:
	ADefensesInitialization();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
