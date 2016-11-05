#include <Commands/Shooter/DefaultState.h>
#include <Commands/Shooter/Intake.h>
#include <Commands/Shooter/ExtentionIn.h>
#include <Commands/Shooter/ExtentionOut.h>
#include <Commands/Shooter/ShooterUp.h>
#include <Commands/Shooter/ShooterManual.h>
DefaultState::DefaultState():
  CommandBase("DefaultState")
{
  // We need the shooter subsystem to not be doing anything else
  Requires(shooter.get());
}

void DefaultState::Initialize() {}

void DefaultState::Execute() {
  if(oi->operatorController->GetRawButton(oi->Back)) {
    shooter->SetFlashlight(true);
  } else {
    shooter->SetFlashlight(false);
  }
  shooter->PivotGotoAngle(0.0);
  shooter->SetShooter(0.0);
  shooter->SetRollers(0.0);


  if(oi->operatorController->GetRawButton(oi->OperatorButton::A)) {
      Scheduler::GetInstance()->AddCommand(new Intake());
  }

  if(oi->operatorController->GetRawButton(oi->OperatorButton::Y)) {
      Scheduler::GetInstance()->AddCommand(new ShooterUp());
  }

  // if(oi->operatorController->GetRawButton(oi->OperatorButton::Start)) {
  //   Scheduler::GetInstance()->AddCommand(new ShooterManual());
  // }
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
