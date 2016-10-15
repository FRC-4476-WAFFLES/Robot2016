#pragma once

#include "CommandBase.h"

class DefaultState: public CommandBase {
public:
	DefaultState();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
