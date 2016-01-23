#include "ADefensesSubsystem.h"
#include "../RobotMap.h"

ADefensesSubsystem::ADefensesSubsystem() :
		PIDSubsystem("ADefensesSubsystem",0,0,0,0)
{

	Motor = new Victor(4);
	Potentiometer = new AnalogPotentiometer(5);
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




