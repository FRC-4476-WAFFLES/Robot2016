/**
 * ADefensesSubsystem is a class that keeps references to each of the
 * manipulators and sensors that are used by the a defenses subsystem.
 */

#include "ADefensesSubsystem.h"
#include "../RobotMap.h"

ADefensesSubsystem::ADefensesSubsystem():
	PIDSubsystem("ADefensesSubsystem", 0.03, 0.000, 0.000)
{
	Motor = new Victor(A_DEFENSES_MOTOR);
	Potentiometer = new VexEncoder(A_DEFENSES_POT);
	PorticulusIndex = 1;
	ChevalDeFrisseIndex = 0;
}

void ADefensesSubsystem::InitDefaultCommand()
{
	// No default command
}

// Input for the PID in this PIDSubsystem
double ADefensesSubsystem::ReturnPIDInput() {
	return Potentiometer->GetAngle();
}

// Output for the PID in this PIDSubsystem
void ADefensesSubsystem::UsePIDOutput(double power){
	Motor->PIDWrite(-power);
}

// Keeps track of which portculus setpoint we are at and moves to the next one.
void ADefensesSubsystem::GoToNextPorticulusSetpoint()
{
	Enable();
	switch(PorticulusIndex){
				case 0:
					SetSetpoint(40);
					break;
				case 1:
					SetSetpoint(254);
					break;
				default:
				case 2:
					SetSetpoint(210);
					PorticulusIndex = -1;
					break;
	}
	PorticulusIndex++;
}

void ADefensesSubsystem::ADefensesReset()
{
	PorticulusIndex = 0;
	ChevalDeFrisseIndex = 0;
}


// Keeps track of which cheval setpoint we are at and moves to the next one.
void ADefensesSubsystem::GoToNextChevalDeFrisseSetpoint()
{
	Enable();
		switch(ChevalDeFrisseIndex){
		case 0:
			SetSetpoint(40);
			break;
		case 1:
			//todo: Change this setpoint so that it right over the lowest position
			SetSetpoint(200);
					break;

		case 2:
			SetSetpoint(261);
			ChevalDeFrisseIndex = -1;
			break;
		}

		ChevalDeFrisseIndex++;
}
