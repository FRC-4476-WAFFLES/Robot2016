#pragma once

#include "CommandBase.h"

class ShooterUp: public CommandBase {
public:
	ShooterUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
