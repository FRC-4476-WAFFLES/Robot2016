#include <Commands/Auto/OuttakeShootAuto.h>
#include <Commands/Shooter/Intake.h>
#include <Commands/Shooter/ExtentionOut.h>
OuttakeShootAuto::OuttakeShootAuto():
  CommandBase("OuttakeShootAuto")
{

}

void OuttakeShootAuto::Initialize() {
  t.Stop();
  t.Reset();
}

void OuttakeShootAuto::Execute() {
  shooter->PivotGotoAngle(shooter->shot_angle);
  shooter->SetShooter(30.0);

  if(shooter->ShooterOnTarget()){
      t.Start();
      shooter->SetRollers(shooter->roller_out);
  } else{
      t.Stop();
      t.Reset();
      shooter->SetRollers(shooter->roller_in);
  }
}

bool OuttakeShootAuto::IsFinished() {
  // The command is done after a shot has fired
  return t.HasPeriodPassed(1.0);
}

void OuttakeShootAuto::End() {
  shooter->PivotGotoAngle(0.0);
  shooter->SetShooter(0.0);
  shooter->SetRollers(0.0);
}

void OuttakeShootAuto::Interrupted() {
  this->End();
}
