#include "OI.h"
#include "Commands/IntakeIn.h"
#include "Commands/IntakeOut.h"
#include "Commands/OperatorDrive.h"

OI::OI()
{
	// Process operator interface input here.
	joystickLeft = new Joystick(0);
	joystickRight = new Joystick(1);
	operatorController = new Joystick(2);
	intakeInButton = new JoystickButton(operatorController, 5);
	intakeInButton->WhenPressed(new IntakeIn());
	intakeOutButton = new JoystickButton(operatorController, 6);
	intakeOutButton->WhenPressed(new IntakeOut());

}


