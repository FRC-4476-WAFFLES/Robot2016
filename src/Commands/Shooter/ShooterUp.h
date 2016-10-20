#pragma once

#include "CommandBase.h"

class ShooterUp: public CommandBase {
private:
  Timer shot_timer;
public:
	ShooterUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
