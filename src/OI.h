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

};

#endif
