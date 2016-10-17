#pragma once

#include "CommandBase.h"

class ExtentionDefaultState: public CommandBase {
public:
	ExtentionDefaultState();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	int extention_state = 0;

};
