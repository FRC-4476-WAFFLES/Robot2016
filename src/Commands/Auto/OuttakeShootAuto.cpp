#include <Commands/Auto/OuttakeShootAuto.h>
#include <Commands/Shooter/Intake.h>
#include <Commands/Shooter/ExtentionOut.h>
OuttakeShootAuto::OuttakeShootAuto():
  CommandBase("OuttakeShootAuto")
{

}

void OuttakeShootAuto::Initialize() {}

void OuttakeShootAuto::Execute() {
  shooter->PivotGotoAngle(shooter->shot_angle);
  shooter->SetShooter(30.0);

    if(shooter->ShooterOnTarget()){
	  shooter->SetRollers(shooter->roller_out);
    } else{
	  shooter->SetRollers(shooter->roller_in);
    }


}

bool OuttakeShootAuto::IsFinished() {
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
