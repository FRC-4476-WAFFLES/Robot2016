#include <Commands/Shooter/ShooterUp.h>
#include <Commands/Shooter/Intake.h>
#include <Commands/Shooter/ExtentionOut.h>
#include <Commands/Shooter/ExtentionIn.h>

ShooterUp::ShooterUp():
  CommandBase("ShooterUp")
{
  // We need the ShooterUper subsystem to not be doing anything else
  Requires(shooter.get());
}

void ShooterUp::Initialize() {}

void ShooterUp::Execute() {
  shooter->PivotGotoAngle(shooter->shot_angle);
  if (extention->GetCurrentCommand()->GetName() == "ExtentionOut") {
    shooter->SetFlashlight(true);
    shooter->SetShooter(shooter->shot_speed);

    if (oi->operatorController->GetRawButton(oi->OperatorButton::B)) {
	shot_timer.Start();
	shooter->SetRollers(shooter->roller_out);
    } else {
	shooter->SetRollers(shooter->roller_in);

	// Move extension in after shot
	if(shot_timer.HasPeriodPassed(0.5)) {
	    Scheduler::GetInstance()->AddCommand(new ExtentionIn());
	}
	// Don't count this time towards the button getting held down
	shot_timer.Stop();
	shot_timer.Reset();
    }
  } else {
    shooter->PivotGotoAngle(shooter->shot_angle);
    auto axis = oi->operatorController->GetRawAxis(1);
    axis = axis > 0.0 ? axis : 0.0;
    shooter->SetShooter(axis*shooter->shooter_intake_speed);
    shooter->SetRollers(axis);

    // Don't count this time towards the button getting held down
    shot_timer.Stop();
    shot_timer.Reset();
  }



  if(oi->operatorController->GetRawButton(oi->OperatorButton::A)) {
      Scheduler::GetInstance()->AddCommand(new Intake());
  }
}

bool ShooterUp::IsFinished() {
  return false;
}

void ShooterUp::End() {
  shooter->PivotGotoAngle(0.0);
  shooter->SetShooter(0.0);
  shooter->SetRollers(0.0);
}

void ShooterUp::Interrupted() {
  this->End();
}
