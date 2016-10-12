#include <Commands/Shooter/Shoot.h>

Shoot::Shoot():
  CommandBase("DriveAuto")
{
  // We need the shooter subsystem to not be doing anything else
  Requires(shooter.get());
}

void Shoot::Initialize() {}

void Shoot::Execute() {
  shooter->PivotGotoAngle(shooter->shot_angle);
  shooter->SetShooter(shooter->shot_speed);
  shooter->SetExtension(shooter->extension_out);

  if (shooter->ShooterOnTarget() && shooter->PivotOnTarget()) {
    shooter->SetRollers(shooter->roller_out);
  } else {
    shooter->SetRollers(shooter->roller_in);
  }

  // TODO: Example
  if(oi->operatorController->GetRawButton(oi->OperatorButton::B)) {
    shooter->SetCurrentCommand(new Shoot());
  }
}

bool Shoot::IsFinished() {
  return false;
}

void Shoot::End() {
  shooter->PivotGotoAngle(0.0);
  shooter->SetShooter(0.0);
  shooter->SetExtension(0.0);
  shooter->SetRollers(0.0);
}

void Shoot::Interrupted() {
  this->End();
}
