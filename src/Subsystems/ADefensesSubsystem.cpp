#include "ADefensesSubsystem.h"
#include "../RobotMap.h"
#include "Commands/ADefensesGoToAngle.h"
ADefensesSubsystem::ADefensesSubsystem() :
		PIDSubsystem("ADefensesSubsystem",0.000,0.000,0.000)
{
	Motor = new Victor(A_DEFENSES_MOTOR);
	Potentiometer = new VexEncoder(A_DEFENSES_POT);
}

void ADefensesSubsystem::InitDefaultCommand()
{
	SetDefaultCommand(new ADefensesGoToAngle(0));

}

double ADefensesSubsystem::ReturnPIDInput() {
	rawAngle = Potentiometer->GetAngle();
	SmartDashboard::PutNumber("ADefenseAngle", rawAngle);
	return rawAngle;

}

void ADefensesSubsystem::UsePIDOutput(double power){
	Motor->PIDWrite(power);
}




