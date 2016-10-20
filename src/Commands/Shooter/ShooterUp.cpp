#include <Commands/Shooter/ShooterUp.h>
#include <Commands/Shooter/Intake.h>
#include <Commands/Shooter/ExtentionOut.h>
ShooterUp::ShooterUp():
  CommandBase("ShooterUp")
{
  // We need the ShooterUper subsystem to not be doing anything else
  Requires(shooter.get());
}

void ShooterUp::Initialize() {}

void ShooterUp::Execute() {

    if (extention->GetCurrentCommand()->GetName() == "ExtentionOut"){
      shooter->PivotGotoAngle(shooter->shot_angle);
      shooter->SetShooter(shooter->shot_speed);
      SmartDashboard::PutString("check one","complete");

      if (oi->operatorController->GetRawButton(oi->OperatorButton::B)) {
	  shooter->SetRollers(shooter->roller_out);
      } else {
	  shooter->SetRollers(shooter->roller_in);
      }
  } else {
    shooter->PivotGotoAngle(shooter->shot_angle);
    shooter->SetShooter(0.0);
    shooter->SetRollers(0.0);
    SmartDashboard::PutString("check one","not complete");
  }



  if(oi->operatorController->GetRawButton(oi->OperatorButton::A)) {
      Scheduler::GetInstance()->AddCommand(new Intake());
  }


}

bool ShooterUp::IsFinished() {
  return false;
}

void ShooterUp::End() {
  shooter->PivotGotoAngle(0.0);
  shooter->SetShooter(0.0);
  shooter->SetRollers(0.0);
}

void ShooterUp::Interrupted() {
  this->End();
}
