#ifndef SCALER_RELEASE_H
#define SCALER_RELEASE_H

#include "CommandBase.h"
#include "WPILib.h"

class ScalerRelease: public CommandBase
{
private:
	Timer* t;
public:

	ScalerRelease();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
