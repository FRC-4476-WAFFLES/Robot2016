#include <Commands/Shooter/ExtentionIn.h>
#include <Commands/Shooter/ExtentionOut.h>
#include <Commands/Shooter/ShooterUp.h>
#include <Commands/Shooter/Intake.h>
ExtentionIn::ExtentionIn():
  CommandBase("ExtentionIn")
{
  Requires(extention.get());

}

void ExtentionIn::Initialize() {}

void ExtentionIn::Execute() {
  shooter->SetExtension(shooter->extention_in);

  if(oi->operatorController->GetRawButton(oi->OperatorButton::X) && extention_state == 1){
      Scheduler::GetInstance()->AddCommand(new ExtentionOut());
      Scheduler::GetInstance()->AddCommand(new ShooterUp());
  }
  if(!oi->operatorController->GetRawButton(oi->OperatorButton::X)){
      extention_state = 1;
  }

  if(oi->operatorController->GetRawButton(oi->OperatorButton::BumperBottomLeft)) {
      Scheduler::GetInstance()->AddCommand(new ExtentionOut());
      Scheduler::GetInstance()->AddCommand(new Intake());
  }

}

bool ExtentionIn::IsFinished() {
  return false;
}

void ExtentionIn::End() {

}

void ExtentionIn::Interrupted() {
  this->End();
}
