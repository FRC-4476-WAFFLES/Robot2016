#ifndef A_DEFENSES_COMMAND_GROUP_H
#define A_DEFENSES_COMMAND_GROUP_H

#include "../CommandBase.h"
#include "WPILib.h"

class ADefensesCommandGroup: public CommandGroup
{
private:

public:
	ADefensesCommandGroup();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
