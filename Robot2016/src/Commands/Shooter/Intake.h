#pragma once

#include "CommandBase.h"

class Intake: public CommandBase {
public:
	Intake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
