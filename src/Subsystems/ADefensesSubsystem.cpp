#include "ADefensesSubsystem.h"
#include "../RobotMap.h"

ADefensesSubsystem::ADefensesSubsystem() :
		PIDSubsystem("ADefensesSubsystem",0,0,0,0)
{
	Motor = new Victor(A_DEFENSES_MOTOR);
	Potentiometer = new AnalogPotentiometer(A_DEFENSES_POT);
}

void ADefensesSubsystem::InitDefaultCommand()
{
	//SetDefaultCommand(new MySpecialCommand());

}

double ADefensesSubsystem::ReturnPIDInput() {
	return Potentiometer->PIDGet();
}

void ADefensesSubsystem::UsePIDOutput(double power){
	Motor->PIDWrite(power);
}




