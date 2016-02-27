#ifndef AUTO_DO_NOTHING_H
#define AUTO_DO_NOTHING_H
// gives the command it`s name


#include "../CommandBase.h"
#include "WPILib.h"

// tells the command what it is
class AutoDoNothing: public CommandBase
{
public:
	// tells the command what functions will be used
	AutoDoNothing();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
