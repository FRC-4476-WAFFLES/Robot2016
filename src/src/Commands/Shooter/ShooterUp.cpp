#include <Commands/Shooter/ShooterUp.h>

ShooterUp::ShooterUp():
  CommandBase("ShooterUp")
{
  // We need the ShooterUper subsystem to not be doing anything else
  Requires(shooter.get());
}

void ShooterUp::Initialize() {}

void ShooterUp::Execute() {
  shooter->PivotGotoAngle(shooter->shot_angle);
  shooter->SetShooter(0.0);
  shooter->SetRollers(0.0);

}

bool ShooterUp::IsFinished() {
  return false;
}

void ShooterUp::End() {
  shooter->PivotGotoAngle(0.0);
}

void ShooterUp::Interrupted() {
  this->End();
}
