#ifndef SCALER_STOP_H
#define SCALER_STOP_H

#include "CommandBase.h"
#include "WPILib.h"

class ScalerStop: public CommandBase
{
private:
	Timer* t;
public:
	ScalerStop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
