#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
public:
	OI();
	Joystick* joystickLeft;
	Joystick* joystickRight;
	Joystick* operatorController;
	Button* intakeInButton;
	Button* intakeOutButton;
	Button* RollerSuckButton;
	Button* RollerExtractButton;
	Button* ADefencesButton;
	Button* ScalerDeployButton;
	Button* ScalerRetractButton;
	Button* ManualInatke;
	Button* IntakeHalfWayPointButton;
 	Button* ReverseSpoolButton;
	Button* AutoScaler;
	Button* ChevalDeFrisseButton;
};

#endif
