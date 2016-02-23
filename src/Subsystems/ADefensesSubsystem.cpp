#include "ADefensesSubsystem.h"
#include "../RobotMap.h"
#include "Commands/Porticulus.h"
#include "Commands/ChevalDeFrisse.h"

ADefensesSubsystem::ADefensesSubsystem():

// keepGoingUpForP(space)UntilItStartsToWabbleAndThenAdjustDspace)Slowly

PIDSubsystem("ADefensesSubsystem", 0.03, 0.000, 0.000)
{
	Motor = new Victor(A_DEFENSES_MOTOR);
	Potentiometer = new VexEncoder(A_DEFENSES_POT);
	PorticulusIndex = 1;
	ChevalDeFrisseIndex = 0;
}

void ADefensesSubsystem::InitDefaultCommand()
{
}

double ADefensesSubsystem::ReturnPIDInput() {
	return Potentiometer->GetAngle();
}

void ADefensesSubsystem::UsePIDOutput(double power){
	Motor->PIDWrite(-power);
}

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

void ADefensesSubsystem::GoToNextChevalDeFrisseSetpoint()
{
	Enable();
		switch(ChevalDeFrisseIndex){
		case 0:
			SetSetpoint(40);
			break;

		case 1:
			SetSetpoint(261);
			ChevalDeFrisseIndex = -1;
			break;
		}

		ChevalDeFrisseIndex++;
}
