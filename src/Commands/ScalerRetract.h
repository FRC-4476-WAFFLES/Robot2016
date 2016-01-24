#ifndef SCALER_RETRACT_H
#define SCALER_RETRACT_H
#include "../CommandBase.h"
#include "WPILib.h"

class ScalerRetract: public CommandBase
{
private:

public:

	ScalerRetract();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
