#include "OI.h"
#include "Commands/DriveOperator.h"
#include "Commands/RollerSuck.h"
#include "Commands/ScalerCommandGroup.h"
#include "Commands/IntakeIn.h"
#include "Commands/IntakeOut.h"
#include "Commands/RollerExtract.h"
#include "Commands/ScalerRetract.h"
#include "Commands/ScalerDeploy.h"
#include "Commands/IntakeHalfWayPoint.h"
#include "Commands/Porticulus.h"
#include "Commands/ScalerScale.h"

OI::OI()
{
	/*
	Button:
	X(In use)
	A(In use)
	B(In use)
	Y(In use)
	Top left bumper(In use)
	Top right bumper(In use)
	Bottom left bumper(In use)
	Bottom right bumper(In use)
	Back Button
	Start Button
	*/
	//Options between button types: WhenPressed, WhileHeld, ToggleWhenPressed
	// Process operator interface input here.

	// Joystick port declarations
	joystickLeft = new Joystick(0);
	joystickRight = new Joystick(1);
	operatorController = new Joystick(2);

	// Commands
	{
		Button* temp;

		/****************Intake****************/
		temp = new JoystickButton(operatorController, OperatorButton::BumperTopLeft);
		temp->WhenPressed(new IntakeIn());
		temp = new JoystickButton(operatorController, OperatorButton::Y);
		temp->WhenPressed(new IntakeHalfWayPoint());
		temp = new JoystickButton(operatorController, OperatorButton::BumperTopRight);
		temp->WhenPressed(new IntakeOut());

		temp = new JoystickButton(operatorController, OperatorButton::X);
		temp->WhileHeld(new RollerSuck());
		temp = new JoystickButton(operatorController, OperatorButton::A);
		temp->WhileHeld(new RollerExtract());

		/****************Scaler****************/
		//temp = new JoystickButton(operatorController, ?);
		//temp->WhileHeld(new ScalerDeploy());
		temp = new JoystickButton(operatorController, OperatorButton::BumperBottomLeft);
		temp->WhileHeld(new ScalerRetract());
		temp = new JoystickButton(operatorController, OperatorButton::BumperBottomRight);
		temp->WhileHeld(new ScalerScale());

		/**************A Defenses**************/
		temp = new JoystickButton(operatorController, OperatorButton::B);
		temp->WhenPressed(new Porticulus());
	}
}
