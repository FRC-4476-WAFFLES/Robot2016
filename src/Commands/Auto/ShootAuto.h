#pragma once

#include "CommandBase.h"

class ShootAuto: public CommandBase {
public:
	ShootAuto();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
