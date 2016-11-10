#include <Commands/Misc/ChevalMode.h>

ChevalMode::ChevalMode():
  CommandBase("ChevalMode"),
  timer()
{
  Requires(drive.get());
  Requires(shooter.get());
}

void ChevalMode::Initialize() {
  mode = 0;
  start_distance = drive->driveEncoder();
  start_angle = drive->GetGyro();
}

void ChevalMode::Execute() {
  switch(mode) {
    case 0:
      // Move back and raise shooter
      shooter->PivotGotoAngle(shooter->shot_angle);
      shooter->SetShooter(0.0);
      shooter->SetRollers(0.0);

      // Wait for the drive to be within 100 ticks of its target
      if(drive_to(start_distance + 1000, start_angle)) {
        timer.Reset();
        timer.Start();
        mode = 1;
      }
      break;
    case 1:
      // Move forward and slam down shooter
      shooter->PivotGotoAngle(shooter->intake_angle);
      shooter->SetShooter(0.0);
      shooter->SetRollers(0.0);
      drive_to(start_distance - 1000, start_angle);

      // This one's just on a timer
      if(timer.HasPeriodPassed(0.5)) {
        mode = 2;
      }
      break;
  }
}

// Ripped from Commands/Drive/DriveAuto.cpp
bool ChevalMode::drive_to(double distance, double angle) {
  // Calculate the error on the distance traveled
  double distanceError = drive->driveEncoder() - distance;

  // Make sure the distance error does not exceed 100%
  if(distanceError > 1.0) {
    distanceError = 1.0;
  }
  if(distanceError < -1.0) {
    distanceError = -1.0;
  }

  // Calculate the difference between the current angle and the desired angle
  double angleError = angle - drive->GetGyro();

  // Set the motors to run
  drive->Drive(0.1*angleError - distanceError, 0.1*angleError - distanceError);

  return abs(drive->driveEncoder() - distance) < 100.0;
}

bool ChevalMode::IsFinished() {
  // End if the action is finished or the operator presses a button
  return mode > 1 || oi->operatorController->GetRawButton(oi->OperatorButton::A) || oi->operatorController->GetRawButton(oi->OperatorButton::Y) ||
  oi->operatorController->GetRawButton(oi->OperatorButton::X);
}

void ChevalMode::End() {
  drive->Drive(0.0, 0.0);
  shooter->PivotGotoAngle(0.0);
  shooter->SetShooter(0.0);
  shooter->SetRollers(0.0);
}

void ChevalMode::Interrupted() {
  this->End();
}
