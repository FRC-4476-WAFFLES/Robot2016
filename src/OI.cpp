#include <Commands/RollerSuck.h>
#include "OI.h"
#include "Commands/IntakeIn.h"
#include "Commands/IntakeOut.h"
#include "Commands/OperatorDrive.h"
#include "Commands/RollerExtract.h"
#include "Commands/ScalerRetract.h"
#include "Commands/ScalerDeploy.h"
#include "Commands/IntakeHalfWayPoint.h"
#include "Commands/ChevalDeFrisse.h"
#include "Commands/Porticulus.h"
OI::OI()
{

//		std::unique_ptr<Command> autonomousCommand;
//		SendableChooser *chooser;
//		CommandBase::init();
//		chooser = new SendableChooser();
//		chooser->AddDefault("ChevalDeFrisse", new ChevalDeFrisse());
//		chooser->AddObject("Porticulus", new Porticulus());
//
//		SmartDashboard::PutData("Auto Modes", chooser);





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
	//Options between button types: WhenPressed, WhileHeld, ToggleWhenPressed
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
	ScalerDeployButton = new JoystickButton(operatorController, 8);
	ScalerDeployButton->WhileHeld(new ScalerDeploy());
	ScalerRetractButton = new JoystickButton(operatorController, 7);
	ScalerRetractButton->WhileHeld(new ScalerRetract());
	IntakeHalfWayPointButton =new JoystickButton (operatorController, 4);
	IntakeHalfWayPointButton->WhenPressed(new IntakeHalfWayPoint());
	ADefencesButton= new JoystickButton(operatorController, 3);
	ADefencesButton->WhenPressed(new Porticulus());
	//Substitute Porticulus with cheval de frisse command for test
}


