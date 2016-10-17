#pragma once

#include "CommandBase.h"

class ExtentionIn: public CommandBase {
public:
	ExtentionIn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	int extention_state = 0;
};
