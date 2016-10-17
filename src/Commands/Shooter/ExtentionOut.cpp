#include <Commands/Shooter/ExtentionOut.h>
#include <Commands/Shooter/ExtentionIn.h>
#include <Commands/Shooter/ShooterUp.h>
#include <Commands/Shooter/Intake.h>
ExtentionOut::ExtentionOut():
  CommandBase("ExtentionOut")
{
  Requires(extention.get());
}

void ExtentionOut::Initialize() {}

void ExtentionOut::Execute() {
  shooter->SetExtension(shooter->extention_out);

  if(oi->operatorController->GetRawButton(oi->OperatorButton::X) && extention_state == 1){
      Scheduler::GetInstance()->AddCommand(new ExtentionIn());
  }

  if(!oi->operatorController->GetRawButton(oi->OperatorButton::X)){
      extention_state = 1;
  }

  if(oi->operatorController->GetRawButton(oi->OperatorButton::BumperTopLeft)) {
      Scheduler::GetInstance()->AddCommand(new ExtentionOut());
      Scheduler::GetInstance()->AddCommand(new Intake());
  }

}

bool ExtentionOut::IsFinished() {
  return false;
}

void ExtentionOut::End() {

}

void ExtentionOut::Interrupted() {
  this->End();
}
