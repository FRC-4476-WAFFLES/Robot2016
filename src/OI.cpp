#include <Commands/DriveOperator.h>
#include <Commands/RollerSuck.h>
#include <Commands/ScalerCommandGroup.h>
#include "OI.h"
#include "Commands/IntakeIn.h"
#include "Commands/IntakeOut.h"
#include "Commands/RollerExtract.h"
#include "Commands/ScalerRetract.h"
//#include "Commands/ScalerDeploy.h"
#include "Commands/IntakeHalfWayPoint.h"
#include "Commands/Porticulus.h"
#include "Commands/ScalerScale.h"
OI::OI()
{
	/*
	Button:
	1=X(In use)
	2=A(In use)
	3=B(In use)
	4=Y(In use)
	5=Top left bumper(In use)
	6=Top right bumper(In use)
	7=Bottom left bumper(In use)
	8=Bottom right bumper(In use)
	9=Back Button(In use)
	10=Start Button(In use)
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
	//ScalerDeployButton = new JoystickButton(operatorController, 8);
	//ScalerDeployButton->WhileHeld(new ScalerDeploy());
	ScalerRetractButton = new JoystickButton(operatorController, 7);
	ScalerRetractButton->WhileHeld(new ScalerRetract());
	IntakeHalfWayPointButton =new JoystickButton (operatorController, 4);
	IntakeHalfWayPointButton->WhenPressed(new IntakeHalfWayPoint());
	ADefencesButton= new JoystickButton(operatorController, 3);
	ADefencesButton->WhenPressed(new Porticulus());
	ReverseSpoolButton = new JoystickButton(operatorController, 8);
	ReverseSpoolButton->WhileHeld(new ScalerScale());

}
