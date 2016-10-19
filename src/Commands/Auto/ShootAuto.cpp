#include <Commands/Auto/ShootAuto.h>
#include <Commands/Shooter/Intake.h>
#include <Commands/Shooter/ExtentionOut.h>
ShootAuto::ShootAuto():
  CommandBase("ShootAuto")
{

}

void ShootAuto::Initialize() {}

void ShootAuto::Execute() {
  shooter->PivotGotoAngle(shooter->shot_angle);
  shooter->SetShooter(shooter->shot_speed);

    if(shooter->ShooterOnTarget()){
	  shooter->SetRollers(shooter->roller_out);
    } else{
	  shooter->SetRollers(shooter->roller_in);
    }








}

bool ShootAuto::IsFinished() {
  return false;
}

void ShootAuto::End() {
  shooter->PivotGotoAngle(0.0);
  shooter->SetShooter(0.0);
  shooter->SetRollers(0.0);
}

void ShootAuto::Interrupted() {
  this->End();
}
