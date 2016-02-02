#include <Commands/RollerSuck.h>
#include "OI.h"
#include "Commands/IntakeIn.h"
#include "Commands/IntakeOut.h"
#include "Commands/OperatorDrive.h"
#include "Commands/RollerExtract.h"
#include "Commands/ADefensesCommandGroup.h"
#include "Commands/ScalerRetract.h"
#include "Commands/ScalerDeploy.h"
OI::OI()
{
	/*
	Button:
	1=X
	2=A
	3=B
	4=Y
	5=Top left bumper
	6=Top right bumper
	7=Bottom left bumper
	8=Bottom right bumper
	9=Back Button
	10=Start Button
	*/

	// Process operator interface input here.
	joystickLeft = new Joystick(0);
	joystickRight = new Joystick(1);
	operatorController = new Joystick(2);
	intakeInButton = new JoystickButton(operatorController, 5);
	intakeInButton->WhenPressed(new IntakeIn());
	intakeOutButton = new JoystickButton(operatorController, 6);
	intakeOutButton->WhenPressed(new IntakeOut());
	RollerSuckButton = new JoystickButton(operatorController, 1);
	RollerSuckButton->WhileHeld(new RollerSuck());
	RollerExtractButton = new JoystickButton(operatorController, 2);
	RollerExtractButton->WhileHeld(new RollerExtract());
	ADefencesButton = new JoystickButton(operatorController, 3);
	ADefencesButton->WhenPressed(new ADefensesCommandGroup());
	ScalerDeployButton = new JoystickButton(operatorController, 8);
	ScalerDeployButton->WhenPressed(new ScalerDeploy());
	ScalerRetractButton = new JoystickButton(operatorController, 7);
	ScalerRetractButton->WhenPressed(new ScalerRetract());
}


