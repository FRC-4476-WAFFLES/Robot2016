#ifndef PORTICULUS_H
#define PORTICULUS_H

#include "../CommandBase.h"
#include "WPILib.h"

class Porticulus: public CommandBase
{
private:
	int SequentialIndex;
public:
	Porticulus();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
