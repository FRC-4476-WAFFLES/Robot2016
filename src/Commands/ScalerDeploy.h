#ifndef SCALER_DEPLOY_H
#define SCALER_DEPLOY_H
#include "../CommandBase.h"
#include "WPILib.h"

class ScalerDeploy: public CommandBase
{
private:

public:

	ScalerDeploy();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
