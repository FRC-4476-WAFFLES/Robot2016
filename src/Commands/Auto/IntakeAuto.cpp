#include <Commands/Auto/IntakeAuto.h>

IntakeAuto::IntakeAuto():
  CommandBase("OuttakeShootAuto")
{
  Requires(shooter.get());
}

void IntakeAuto::Initialize() {}

void IntakeAuto::Execute() {
  shooter->PivotGotoAngle(shooter->intake_angle);
  shooter->SetShooter(-1.0*shooter->shooter_intake_speed);
  shooter->SetRollers(shooter->roller_in);
}

bool IntakeAuto::IsFinished() {
  // The command is done after a shot has fired
  return false;
}

void IntakeAuto::End() {
  shooter->PivotGotoAngle(0.0);
  shooter->SetShooter(0.0);
  shooter->SetRollers(0.0);
}

void IntakeAuto::Interrupted() {
  this->End();
}
