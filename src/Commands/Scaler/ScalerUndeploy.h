#ifndef SCALER_UNDEPLOY_H
#define SCALER_UNDEPLOY_H

#include "CommandBase.h"
#include "WPILib.h"

class ScalerUndeploy: public CommandBase
{
public:
	ScalerUndeploy();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
