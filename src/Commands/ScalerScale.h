#ifndef SCALER_SCALE_H
#define SCALER_SCALE_H
#include "../CommandBase.h"
#include "WPILib.h"

class ScalerScale: public CommandBase
{
private:

public:

	ScalerScale();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
