#include <Commands/Shooter/DefaultState.h>
#include <Commands/Shooter/Shoot.h>
#include <Commands/Shooter/Intake.h>
#include <Commands/Shooter/ExtentionIn.h>
#include <Commands/Shooter/ExtentionOut.h>
DefaultState::DefaultState():
  CommandBase("DefaultState")
{
  // We need the shooter subsystem to not be doing anything else
  Requires(shooter.get());
}

void DefaultState::Initialize() {}

void DefaultState::Execute() {
  shooter->PivotGotoAngle(0.0);
  shooter->SetShooter(0.0);
  shooter->SetRollers(0.0);

  if(oi->operatorController->GetRawButton(oi->OperatorButton::B)) {
    shooter->SetCurrentCommand(new Shoot());
  }

  if(oi->operatorController->GetRawButton(oi->OperatorButton::A)) {
    shooter->SetCurrentCommand(new Intake());
  }

  if(oi->operatorController->GetRawButton(oi->OperatorButton::BumperTopRight)) {
    shooter->SetCurrentCommand(new ExtentionIn());
  }
  if(oi->operatorController->GetRawButton(oi->OperatorButton::BumperTopLeft)) {
    shooter->SetCurrentCommand(new ExtentionOut());
  }

  if(oi->operatorController->GetRawButton(oi->OperatorButton::Y)) {
    shooter->SetCurrentCommand(new ShooterUp());
  }
}

bool DefaultState::IsFinished() {
  return false;
}

void DefaultState::End() {
  shooter->PivotGotoAngle(0.0);
  shooter->SetShooter(0.0);
  shooter->SetRollers(0.0);
}

void DefaultState::Interrupted() {
  this->End();
}
