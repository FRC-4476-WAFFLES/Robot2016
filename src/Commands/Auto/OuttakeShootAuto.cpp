#include <Commands/Auto/OuttakeShootAuto.h>
#include <Commands/Shooter/Intake.h>
#include <Commands/Shooter/ExtentionOut.h>
OuttakeShootAuto::OuttakeShootAuto():
  CommandBase("OuttakeShootAuto"),
  t_running(false)
{
  t.reset(new Timer());
}

void OuttakeShootAuto::Initialize() {
  t->Stop();
  t->Reset();
}

void OuttakeShootAuto::Execute() {
  shooter->PivotGotoAngle(shooter->shot_angle);
  shooter->SetShooter(30.0);

  if (shooter->ShooterOnTarget()){
      if (!t_running) {
	  t->Start();
	  t_running = true;
      }
      shooter->SetRollers(shooter->roller_out);
  } else{
      if (t_running) {
	t->Stop();
	t->Reset();
	t_running = false;
      }
      shooter->SetRollers(shooter->roller_in);
  }
}

bool OuttakeShootAuto::IsFinished() {
  // The command is done after a shot has fired
  return false;
}

void OuttakeShootAuto::End() {
  shooter->PivotGotoAngle(0.0);
  shooter->SetShooter(0.0);
  shooter->SetRollers(0.0);
}

void OuttakeShootAuto::Interrupted() {
  this->End();
}
