#include <Commands/Shooter/Intake.h>
#include <Commands/Shooter/ShooterUp.h>
#include <Commands/Misc/ChevalMode.h>
#include <algorithm>

Intake::Intake():
  CommandBase("Intake")
{
  // We need the shooter subsystem to not be doing anything else
  Requires(shooter.get());
}

void Intake::Initialize() {
}

void Intake::Execute() {
  shooter->PivotGotoAngle(shooter->intake_angle);
  if(fabs(oi->operatorController->GetRawAxis(1)) > 0.05) {
      shooter->SetShooterWithoutTarget(oi->operatorController->GetRawAxis(1)*shooter->shooter_intake_speed);
      shooter->SetRollers(oi->operatorController->GetRawAxis(1));
  } else {
      shooter->SetShooterWithoutTarget(0.0);
      shooter->SetRollers(0.0);
  }

  if(oi->operatorController->GetRawButton(oi->OperatorButton::BumperTopRight)) {
    Scheduler::GetInstance()->AddCommand(new ChevalMode());
  }

  if(oi->operatorController->GetRawButton(oi->OperatorButton::Y)) {
      Scheduler::GetInstance()->AddCommand(new ShooterUp());
  }

}

bool Intake::IsFinished() {
  return false;
}

void Intake::End() {
  shooter->PivotGotoAngle(0.0);
  shooter->SetShooter(0.0);
  shooter->SetRollers(0.0);
}

void Intake::Interrupted() {
  this->End();
}
