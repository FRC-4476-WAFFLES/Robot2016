/**
 * OI is a class that is used to setup user input to the robot.
 */

#include "OI.h"
#include "Commands/Intake/IntakeIn.h"
#include "Commands/Intake/IntakeHalfWayPoint.h"
#include "Commands/Intake/IntakeOutNormal.h"
#include "Commands/Roller/RollerSuck.h"
#include "Commands/Roller/RollerExtract.h"
#include "Commands/Scaler/ScalerDeploy.h"
#include "Commands/ADefenses/ADefensesInitialization.h"
#include "Commands/ADefenses/Porticulus.h"
#include "Commands/ADefenses/ChevalDeFrisse.h"
#include "Commands/Scaler/ScalerCommandGroupUndeploy.h"
#include "Commands/Scaler/ScalerCommandGroupReallignment.h"
#include "Commands/Scaler/ScalerRelease.h"
#include "Commands/Scaler/ScalerStop.h"
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

////	ADefensesChooser = new SendableChooser();
//	ADefensesChooser->AddDefault("Cheval De Frisse", (void*) 0);
//	ADefensesChooser->AddObject("Porticulus", (void*) 1);
//	SmartDashboard::PutData("ADefense types", ADefensesChooser);

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
		temp = new JoystickButton(operatorController, OperatorButton::Back);
		temp->WhenPressed(new ScalerCommandGroupUndeploy());
		temp = new JoystickButton(operatorController, OperatorButton::Start);
		temp->WhenPressed(new ScalerCommandGroupReallignment());
		temp = new JoystickButton(operatorController, 11);
		temp->WhenPressed(new ScalerRelease());
		temp = new JoystickButton(operatorController, 12);
		temp->WhenPressed(new ScalerStop());

		/**************A Defenses**************/
		temp = new JoystickButton(operatorController, OperatorButton::B);
		temp->WhenPressed(new ADefensesInitialization());
	}


}
