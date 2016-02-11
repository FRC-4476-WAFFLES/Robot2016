#include "ADefensesSubsystem.h"
#include "../RobotMap.h"

ADefensesSubsystem::ADefensesSubsystem() :
		PIDSubsystem("ADefensesSubsystem",0,0,0)
{
	Motor = new Victor(A_DEFENSES_MOTOR);
	Potentiometer = new VexEncoder(A_DEFENSES_POT);
}

void ADefensesSubsystem::InitDefaultCommand()
{
	//SetDefaultCommand(new MySpecialCommand());

}

double ADefensesSubsystem::ReturnPIDInput() {
	rawAngle = Potentiometer->GetAngle();
	SmartDashboard::PutNumber("RawAngle", rawAngle);
	return Potentiometer->GetAngle();

}

void ADefensesSubsystem::UsePIDOutput(double power){
	Motor->PIDWrite(power);
}




