#include "ADefensesSubsystem.h"
#include "../RobotMap.h"
#include "Commands/Porticulus.h"

ADefensesSubsystem::ADefensesSubsystem():

// keepGoingUpForP(space)UntilItStartsToWabbleAndThenAdjustDspace)Slowly

PIDSubsystem("ADefensesSubsystem",0.001,0.000,0.000)
{
	Motor = new Victor(A_DEFENSES_MOTOR);
	Potentiometer = new VexEncoder(A_DEFENSES_POT);
	PorticulusIndex = 0;
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

void ADefensesSubsystem::GoToNextPorticulusSetpoint()
{
	switch(PorticulusIndex){
				case 0:
					SetSetpoint(23);
					break;
				case 1:
					SetSetpoint(234);
					break;
				case 2:
					SetSetpoint(190);
					PorticulusIndex = -1;
					break;
	}
	PorticulusIndex++;
}

void ADefensesSubsystem::move(float MoveSpeed){

	Disable();
	Motor->SetSpeed(MoveSpeed);

}


