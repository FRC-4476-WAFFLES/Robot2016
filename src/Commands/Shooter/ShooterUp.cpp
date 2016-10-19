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
  shooter->PivotGotoAngle(shooter->shot_angle);
  if (extention->GetCurrentCommand()->GetName() == "ExtentionOut") {
    shooter->SetFlashlight(true);
    shooter->SetShooter(shooter->shot_speed);

    if (oi->operatorController->GetRawButton(oi->OperatorButton::B)) {
	shooter->SetRollers(shooter->roller_out);
    } else {
	shooter->SetRollers(shooter->roller_in);
    }
  } else {
    shooter->SetFlashlight(false);
    shooter->SetShooter(0.0);
    shooter->SetRollers(0.0);
  }

  if(oi->operatorController->GetRawButton(oi->OperatorButton::A)) {
      Scheduler::GetInstance()->AddCommand(new Intake());
  }
}

bool ShooterUp::IsFinished() {
  return false;
}

void ShooterUp::End() {
  shooter->SetFlashlight(false);
  shooter->PivotGotoAngle(0.0);
  shooter->SetShooter(0.0);
  shooter->SetRollers(0.0);
}

void ShooterUp::Interrupted() {
  this->End();
}
