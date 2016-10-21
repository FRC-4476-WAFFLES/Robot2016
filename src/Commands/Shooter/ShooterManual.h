#pragma once

#include "CommandBase.h"

class ShooterManual: public CommandBase {
private:
  Timer shot_timer;
public:
	ShooterManual();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
