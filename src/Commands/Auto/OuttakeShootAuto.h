#pragma once

#include "CommandBase.h"

class OuttakeShootAuto: public CommandBase {
public:
	OuttakeShootAuto();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
