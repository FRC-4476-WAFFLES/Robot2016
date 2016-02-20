#include "ADefensesSubsystem.h"
#include "../RobotMap.h"


ADefensesSubsystem::ADefensesSubsystem():

// keepGoingUpForP(space)UntilItStartsToWabbleAndThenAdjustDspace)Slowly
	PIDSubsystem("ADefensesSubsystem",0.001,0.000,0.000)
{
	Motor = new Victor(A_DEFENSES_MOTOR);
	Potentiometer = new VexEncoder(A_DEFENSES_POT);
}

void ADefensesSubsystem::InitDefaultCommand()
{


}

double ADefensesSubsystem::ReturnPIDInput() {
	rawAngle = Potentiometer->GetAngle();
	SmartDashboard::PutNumber("ADefenseAngle", rawAngle);
	return rawAngle;

}

void ADefensesSubsystem::UsePIDOutput(double power){
	Motor->PIDWrite(power);
}


