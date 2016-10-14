#pragma once

#include "CommandBase.h"

class ExtentionOut: public CommandBase {
public:
	ExtentionOut();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
