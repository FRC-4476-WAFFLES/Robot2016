#include <Commands/Shooter/DefaultState.h>
#include <Commands/Shooter/Shoot.h>
#include <Commands/Shooter/Intake.h>
#include <Commands/Shooter/ExtentionIn.h>
#include <Commands/Shooter/ExtentionOut.h>
#include <Commands/Shooter/ShooterUp.h>

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
      Scheduler::GetInstance()->AddCommand(new Shoot());
  }

  if(oi->operatorController->GetRawButton(oi->OperatorButton::A)) {
      Scheduler::GetInstance()->AddCommand(new Intake());
  }

  if(oi->operatorController->GetRawButton(oi->OperatorButton::Y)) {
      Scheduler::GetInstance()->AddCommand(new ShooterUp());
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
