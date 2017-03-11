#include "WPILib.h"

#include "Commands/Auto/AutoDoNothing.h"
#include "Commands/Auto/AutoDriveForwardLowBar.h"

#include "CommandBase.h"
#include "Commands/Auto/AutoScore.h"
#include "Commands/Auto/AutoDriveReverse.h"
#include "Commands/Auto/ChevalDeFrisseAuto.h"
#include "Commands/Auto/PorticulusAuto.h"
#include "Commands/Auto/RoughTerrainAuto.h"

class Robot: public IterativeRobot
{
private:
//	AxisCamera* camera;
	Command* autonomousCommand;
//	SendableChooser* chooser;

//	SendableChooser *ADefesesChooser;
//	Command *ADefenseCommand;

	void RobotInit()
	{
		CommandBase::init();
//		chooser = new SendableChooser();
//		chooser->AddDefault("Nothing Auto", new AutoDoNothing());
//		chooser->AddObject("LowBar Auto", new AutoDriveForwardLowBar());
//		chooser->AddObject("LowBarReverse Auto", new AutoDriveReverse());
//		chooser->AddObject("LowBarScore Auto", new AutoScore());
//		chooser->AddObject("ChevalDeFrisse Auto", new ChevalDeFrisseAuto());
//		chooser->AddObject("Porticulus Auto", new PorticulusAuto());
//		chooser->AddObject("RoughTerrain Auto", new RoughTerrainAuto());
//		SmartDashboard::PutData("Auto Modes", chooser);
//
//		CameraServer::GetInstance()->SetQuality(25);
//		CameraServer::GetInstance()->StartAutomaticCapture("cam0");
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit()
	{
		CommandBase::aDefenses->ADefensesReset();
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
		CommandBase::aDefenses->ADefensesReset();
		CommandBase::drive->ReZero();
		//gets the selected command
//		autonomousCommand = (Command*) chooser->GetSelected();
//		//starts the selected command
		autonomousCommand->Start();
		/* std::string autoSelected = SmartDashboard::GetString("Auto Selector", "Default");
		if(autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		} else {
			autonomousCommand.reset(new ExampleCommand());
		} */



//		if (autonomousCommand != NULL)
//			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		CommandBase::prints();
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		CommandBase::aDefenses->ADefensesReset();
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

