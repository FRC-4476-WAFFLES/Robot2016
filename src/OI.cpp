#include "OI.h"
#include "Commands/DriveOperator.h"
#include "Commands/RollerSuck.h"
#include "Commands/ScalerCommandGroup.h"
#include "Commands/IntakeIn.h"
#include "Commands/IntakeOutNormal.h"
#include "Commands/RollerExtract.h"
#include "Commands/ScalerDeploy.h"
#include "Commands/IntakeHalfWayPoint.h"
#include "Commands/Porticulus.h"
#include "Commands/ScalerCommandGroupUndeploy.h"
#include "Commands/ChevalDeFrisse.h"
#include "Commands/ScalerCommandGroupReallignment.h"
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

	// Commands
	{
		Button* temp;

		/****************Intake****************/
		temp = new JoystickButton(operatorController, OperatorButton::BumperTopLeft);
		temp->WhenPressed(new IntakeIn());
		temp = new JoystickButton(operatorController, OperatorButton::Y);
		temp->WhenPressed(new IntakeHalfWayPoint());
		temp = new JoystickButton(operatorController, OperatorButton::BumperTopRight);
		temp->WhenPressed(new IntakeOutNormal());

		temp = new JoystickButton(operatorController, OperatorButton::X);
		temp->WhileHeld(new RollerSuck());
		temp = new JoystickButton(operatorController, OperatorButton::A);
		temp->WhileHeld(new RollerExtract());

		/****************Scaler****************/
		// temp = new JoystickButton(operatorController, OperatorButton::B);
		// temp->WhileHeld(new ScalerScale());
		// temp = new JoystickButton(operatorController, OperatorButton::BumperBottomLeft);
		// temp->WhileHeld(new ScalerRetract());
		temp = new JoystickButton(operatorController, OperatorButton::Start);
		temp->WhileHeld(new ScalerCommandGroup());
		temp = new JoystickButton(operatorController, OperatorButton::Back);
		temp->WhileHeld(new ScalerCommandGroupUndeploy());
		temp = new JoystickButton(operatorController, OperatorButton::BumperBottomLeft);
		temp->WhileHeld(new ScalerCommandGroupReallignment);

		/**************A Defenses**************/
		temp = new JoystickButton(operatorController, OperatorButton::B);
		temp->WhenPressed(new Porticulus());
		// temp = new JoystickButton(operatorController, OperatorButton::B);
		// temp->WhenPressed(new ChevalDeFrisse());
	}
}
