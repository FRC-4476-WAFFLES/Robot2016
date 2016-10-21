#include <Commands/Shooter/ExtentionDefaultState.h>
#include <Commands/Shooter/Intake.h>
#include <Commands/Shooter/ExtentionIn.h>
#include <Commands/Shooter/ExtentionOut.h>
#include <Commands/Shooter/ShooterUp.h>

ExtentionDefaultState::ExtentionDefaultState():
  CommandBase("ExtentionDefaultState")
{
  // We need the shooter subsystem to not be doing anything else
  Requires(extention.get());
}

void ExtentionDefaultState::Initialize() {}

void ExtentionDefaultState::Execute() {
  shooter->SetExtension(0.0);

  if(oi->operatorController->GetRawButton(oi->OperatorButton::X)) {
      Scheduler::GetInstance()->AddCommand(new ShooterUp());
      Scheduler::GetInstance()->AddCommand(new ExtentionOut());
  }

  if(oi->operatorController->GetRawButton(oi->OperatorButton::BumperBottomLeft)) {
      Scheduler::GetInstance()->AddCommand(new ExtentionOut());
      Scheduler::GetInstance()->AddCommand(new Intake());
  }



}

bool ExtentionDefaultState::IsFinished() {
  return false;
}

void ExtentionDefaultState::End() {
  shooter->SetExtension(0.0);
}

void ExtentionDefaultState::Interrupted() {
  this->End();
}
