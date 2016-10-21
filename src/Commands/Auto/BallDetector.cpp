#include <Commands/Auto/BallDetector.h>
#include <Commands/Shooter/Intake.h>
#include <Commands/Shooter/ExtentionOut.h>
BallDetector::BallDetector():
  CommandBase("BallDetector")
{

}

void BallDetector::Initialize() {}

void BallDetector::Execute() {


  if(shooter->ShooterOnTarget()){

      reached_speed = true;
  }

  if(reached_speed == true){

  }




}

bool BallDetector::IsFinished() {
  return false;
}

void BallDetector::End() {
  shooter->PivotGotoAngle(0.0);
  shooter->SetShooter(0.0);
  shooter->SetRollers(0.0);
}

void BallDetector::Interrupted() {
  this->End();
}
