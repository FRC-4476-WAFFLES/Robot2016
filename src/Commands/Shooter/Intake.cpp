#include <Commands/Shooter/Intake.h>
#include <Commands/Shooter/ShooterUp.h>

Intake::Intake():
  CommandBase("Intake")
{
  // We need the shooter subsystem to not be doing anything else
  Requires(shooter.get());
}

void Intake::Initialize() {
}

void Intake::Execute() {
  shooter->SetFlashlight(false);
  shooter->PivotGotoAngle(shooter->intake_angle);
  shooter->SetShooter(oi->operatorController->GetRawAxis(1)*shooter->shooter_intake_speed);
  shooter->SetRollers(oi->operatorController->GetRawAxis(1));

  if(oi->operatorController->GetRawButton(oi->OperatorButton::Y)) {
      Scheduler::GetInstance()->AddCommand(new ShooterUp());
  }

}

bool Intake::IsFinished() {
  return false;
}

void Intake::End() {
  shooter->SetFlashlight(false);
  shooter->PivotGotoAngle(0.0);
  shooter->SetShooter(0.0);
  shooter->SetRollers(0.0);
}

void Intake::Interrupted() {
  this->End();
}
