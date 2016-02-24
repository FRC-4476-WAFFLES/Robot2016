#ifndef SCALER_SCALE_LONG_H
#define SCALER_SCALE_LONG_H
#include "../CommandBase.h"
#include "WPILib.h"

class ScalerScaleLong: public CommandBase
{
private:
	float LikeLength;
public:

	ScalerScaleLong(float Length);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
