#ifndef A_DEFENSES_GO_TO_ANGLE_H
#define A_DEFENSES_GO_TO_ANGLE_H

#include "../CommandBase.h"
#include "WPILib.h"

class ADefensesGoToAngle: public CommandBase
{
private:
	double angle;
public:
	ADefensesGoToAngle(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
