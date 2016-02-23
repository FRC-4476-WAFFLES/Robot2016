#include <Commands/AutoDriveForwardLowBar.h>
#include "WPILib.h"

#include "Commands/AutoDoNothing.h"
#include "Commands/AutoDriveForwardLowBar.h"
#include "Commands/ChevalDeFrisse.h"
#include "Commands/Porticulus.h"
#include "CommandBase.h"
#include <memory>
#include "iostream"

class Robot: public IterativeRobot
{
private:
	AxisCamera* camera;
	std::unique_ptr<Command> autonomousCommand;
	SendableChooser* chooser;

//	SendableChooser *ADefesesChooser;
//	Command *ADefenseCommand;

	void autonomousInit(){

		CommandBase::init();
				chooser = new SendableChooser();
				//chooser->AddDefault("Auto do nothing", new AutoDoNothing());
				chooser->AddDefault("Low Bar auto", new AutoDriveForwardLowBar());

				SmartDashboard::PutData("Auto Modes", chooser);

				//a def
//		CommandBase::init();
//				ADefesesChooser = new SendableChooser();
//				ADefesesChooser->AddDefault("cheval de frisse a defense", new ChevalDeFrisse());
//				ADefesesChooser->AddDefault("porticulus a defense", new Porticulus());
//
//				SmartDashboard::PutData("a defense mode", ADefesesChooser);

	}

	void RobotInit()
	{

		CommandBase::init();
		chooser = new SendableChooser();
		chooser->AddDefault("Default Auto", new AutoDoNothing());
		chooser->AddDefault("Default Auto", new AutoDriveForwardLowBar());

		SmartDashboard::PutData("Auto Modes", chooser);

		//irrelevant
		CameraServer::GetInstance()->SetQuality(50);
		CameraServer::GetInstance()->StartAutomaticCapture("cam0");

	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit()
	{
	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
		CommandBase::prints();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit()
	{
//		//gets the selected command
//		autonomousCommand.reset((Command*)chooser->GetSelected());
//		//starts the selected command
//		autonomousCommand->Start();
		/* std::string autoSelected = SmartDashboard::GetString("Auto Selector", "Default");
		if(autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		} else {
			autonomousCommand.reset(new ExampleCommand());
		} */

		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		CommandBase::prints();
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
//		ADefenseCommand = (Command*)ADefesesChooser->GetSelected();
//		ADefenseCommand->Start();
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		CommandBase::prints();
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		CommandBase::prints();
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)

