#ifndef CHEVAL_DE_FRISSE_H
#define CHEVAL_DE_FRISSE_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Subsystems/ADefensesSubsystem.h"
class ChevalDeFrisse: public CommandBase
{
private:

public:
	ChevalDeFrisse();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif
