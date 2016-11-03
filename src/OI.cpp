/**
 * OI is a class that is used to setup user input to the robot.
 */

#include "OI.h"
#include "Commands/Shooter/ExtentionIn.h"
#include "Commands/Shooter/ExtentionOut.h"
OI::OI()
{
	/*

	*/
	//Options between button types: WhenPressed, WhileHeld, ToggleWhenPressed
	// Process operator interface input here.

	// Joystick port declarations
	joystickLeft = new Joystick(0);
	joystickRight = new Joystick(1);
	operatorController = new Joystick(2);
}
