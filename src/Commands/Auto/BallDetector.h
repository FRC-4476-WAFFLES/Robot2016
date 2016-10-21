#pragma once

#include "CommandBase.h"

class BallDetector: public CommandBase {
public:
	BallDetector();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	bool reached_speed = false;
};
