#include <Commands/Shooter/ShooterManual.h>
#include <Commands/Shooter/Intake.h>
#include <Commands/Shooter/ExtentionOut.h>
#include <Commands/Shooter/ExtentionIn.h>
#include <Commands/Shooter/DefaultState.h>
#include <Subsystems/ShooterSubsystem.h>
ShooterManual::ShooterManual():
  CommandBase("ShooterManual")
{
  // We need the ShooterManualer subsystem to not be doing anything else
  Requires(shooter.get());
}

void ShooterManual::Initialize() {}

void ShooterManual::Execute() {

  auto roller_speed = oi->operatorController->GetRawAxis(1);
  auto shooter_speed = oi->operatorController->GetRawAxis(2);
  auto extention_speed = oi->operatorController->GetRawAxis(3);
  auto flashlight = oi->operatorController->GetRawButton(oi->OperatorButton::BumperBottomLeft);
  auto pivot_speed = oi->operatorController->GetRawAxis(4);
  shooter->ManualControl(flashlight, extention_speed, shooter_speed, pivot_speed, roller_speed);

  if(oi->operatorController->GetRawButton(oi->OperatorButton::Back)) {
    Scheduler::GetInstance()->AddCommand(new DefaultState());
  }

}

bool ShooterManual::IsFinished() {

  return false;
}

void ShooterManual::End() {
  shooter->PivotGotoAngle(0.0);
  shooter->SetShooter(0.0);
  shooter->SetRollers(0.0);
}

void ShooterManual::Interrupted() {
  this->End();
}
