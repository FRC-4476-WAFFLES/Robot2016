/**
 * ShooterSubsystem is a class that keeps references to each of the
 * motors and provides low-level ways of interacting with the shooter mechanism
 * that can be used by the commands.
 */

#include "ShooterSubsystem.h"
#include "../RobotMap.h"
#include "Commands/Shooter/DefaultState.h"
#include "../OI.h"
ShooterSubsystem::ShooterSubsystem():
  Subsystem("ShooterSubsystem"),
  pivot(new Victor(PIVOT)),
  top_shooter(new Victor(TOP_SHOOTER)),
  bottom_shooter(new Victor(BOTTOM_SHOOTER)),
  top_roller(new Victor(TOP_ROLLER)),
  bottom_roller(new Victor(BOTTOM_ROLLER)),
  extension(new Victor(EXTENSION)),
  flashlight(new Relay(FLASHLIGHT, Relay::kForwardOnly)),
  pivot_e(new VexEncoder(PIVOT_E)),
  extension_e(new NonLoopingVexEncoder(EXTENSION_E)),
  //bottom_hardstop(new DigitalInput(BOTTOM_HARDSTOP)),
  top_shooter_e(new Encoder(TOP_SHOOTER_E, TOP_SHOOTER_E + 1)),
  bottom_shooter_e(new Encoder(BOTTOM_SHOOTER_E, BOTTOM_SHOOTER_E + 1)),
  pivot_pid(new PIDController(-0.0035, 0.0, -0.001, pivot_e, pivot)),
  top_shooter_pid(new PIDController(0.000025, 0.0000125, 0.0, top_shooter_e, top_shooter)),
  bottom_shooter_pid(new PIDController(0.000025, 0.0000125, 0.0, bottom_shooter_e, bottom_shooter)),
  extension_pid(new PIDController(0.01, 0.0, 0.01, extension_e, extension))
{
  // Make the PID for the shooter attempt to reach a speed
  top_shooter_pid->SetPIDSourceType(PIDSourceType::kRate);
  bottom_shooter_pid->SetPIDSourceType(PIDSourceType::kRate);

  // Set the tolerances for the PIDs
  pivot_pid->SetAbsoluteTolerance(5.0);
  top_shooter_pid->SetAbsoluteTolerance(4.0*SHOOTER_ENCODER_COEFFICIENT);
  bottom_shooter_pid->SetAbsoluteTolerance(4.0*SHOOTER_ENCODER_COEFFICIENT);
  extension_pid->SetAbsoluteTolerance(5.0);

  // Invert the bottom shooter
  bottom_shooter->SetInverted(true);
  bottom_roller->SetInverted(true);
}

void ShooterSubsystem::InitDefaultCommand()
{
  // When no other commands are running, we do operator control
  SetDefaultCommand(new DefaultState());
}

void ShooterSubsystem::PivotGotoAngle(double angle)
{
  if(angle != 0.0) {
    pivot_pid->Enable();
    pivot_pid->SetSetpoint(angle);
  } else {
    pivot_pid->Disable();
    pivot->SetSpeed(0.0);
  }
}

bool ShooterSubsystem::PivotOnTarget() {
  return pivot_pid->OnTarget();
}

void ShooterSubsystem::SetRollers(double speed)
{
  top_roller->SetSpeed(speed);
  bottom_roller->SetSpeed(-speed);
}

void ShooterSubsystem::SetShooter(double speed) {
  if(speed != 0.0) {
    if(!top_shooter_pid->IsEnabled() || !top_shooter_pid->GetSetpoint() == speed) {
      top_shooter_pid->Enable();
      top_shooter_pid->SetAbsoluteTolerance(10.0*SHOOTER_ENCODER_COEFFICIENT);
      top_shooter_pid->SetSetpoint(speed*SHOOTER_ENCODER_COEFFICIENT);
      bottom_shooter_pid->Enable();
      bottom_shooter_pid->SetAbsoluteTolerance(10.0*SHOOTER_ENCODER_COEFFICIENT);
      bottom_shooter_pid->SetSetpoint(-speed*SHOOTER_ENCODER_COEFFICIENT);
    }
  } else {
    top_shooter_pid->Disable();
    top_shooter_pid->Reset();
    top_shooter->SetSpeed(0.0);
    bottom_shooter_pid->Disable();
    top_shooter_pid->Reset();
    bottom_shooter->SetSpeed(0.0);
  }
}

void ShooterSubsystem::SetShooterWithoutTarget(double speed) {
  if(speed != 0.0) {
    top_shooter_pid->SetAbsoluteTolerance(0.0);
    top_shooter_pid->Enable();
    top_shooter_pid->SetSetpoint(speed*SHOOTER_ENCODER_COEFFICIENT);
    bottom_shooter_pid->SetAbsoluteTolerance(0.0);
    bottom_shooter_pid->Enable();
    bottom_shooter_pid->SetSetpoint(-speed*SHOOTER_ENCODER_COEFFICIENT);
  } else {
    top_shooter_pid->Disable();
    top_shooter_pid->Reset();
    top_shooter->SetSpeed(0.0);
    bottom_shooter_pid->Disable();
    top_shooter_pid->Reset();
    bottom_shooter->SetSpeed(0.0);
  }
}

bool ShooterSubsystem::ShooterOnTarget() {
  return top_shooter_pid->OnTarget() && bottom_shooter_pid->OnTarget();
}

void ShooterSubsystem::SetExtension(double angle) {
  if(angle != 0.0) {
    extension_pid->Enable();
    extension_pid->SetSetpoint(angle);
  } else {
    extension_pid->Disable();
    extension->SetSpeed(0.0);
  }
}

void ShooterSubsystem::SetFlashlight(bool on) {
  flashlight->Set(on ? Relay::kOn : Relay::kOff);
}

void ShooterSubsystem::ManualControl(bool flashlight, double extension_speed, double shooter_speed, double pivot_speed, float roller_speed) {
  SetFlashlight(flashlight);
  extension_pid->Disable();
  extension->SetSpeed(extension_speed);
  top_shooter_pid->Disable();
  top_shooter->SetSpeed(shooter_speed);
  bottom_shooter_pid->Disable();
  bottom_shooter->SetSpeed(shooter_speed);
  pivot_pid->Disable();
  pivot->SetSpeed(pivot_speed);
  top_roller->SetSpeed(roller_speed);
  bottom_roller->SetSpeed(roller_speed);
}

void ShooterSubsystem::prints() {
  SmartDashboard::PutString("shooter.command", GetCurrentCommand()->GetName());
  SmartDashboard::PutBoolean("shooter.top_on_target", top_shooter_pid->OnTarget());
  SmartDashboard::PutBoolean("shooter.bottom_on_target", bottom_shooter_pid->OnTarget());
  SmartDashboard::PutNumber("shooter.pivot_e [deg]", pivot_e->GetAngle());
  SmartDashboard::PutNumber("shooter.extension_e [deg]", extension_e->GetAngle());
  SmartDashboard::PutNumber("shooter.top_shooter_e [rps]", top_shooter_e->GetRate()/SHOOTER_ENCODER_COEFFICIENT);
  SmartDashboard::PutNumber("shooter.bottom_shooter_e [rps]", bottom_shooter_e->GetRate()/SHOOTER_ENCODER_COEFFICIENT);
  SmartDashboard::PutNumber("shooter.top_shooter_e [rotations]", top_shooter_e->Get()/SHOOTER_ENCODER_COEFFICIENT);
  SmartDashboard::PutNumber("shooter.bottom_shooter_e [rotations]", bottom_shooter_e->Get()/SHOOTER_ENCODER_COEFFICIENT);
}
