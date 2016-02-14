#ifndef INTAKE_HALF_WAY_POINT_H
#define INTAKE_HALF_WAY_POINT_H
#include "../CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"
class IntakeHalfWayPoint: public CommandBase
{
private:

public:

	IntakeHalfWayPoint();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
