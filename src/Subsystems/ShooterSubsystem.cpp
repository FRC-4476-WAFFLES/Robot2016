/**
 * ShooterSubsystem is a class that keeps references to each of the
 * motors and provides low-level ways of interacting with the shooter mechanism
 * that can be used by the commands.
 */

#include "ShooterSubsystem.h"
#include "../RobotMap.h"
#include "Commands/Shooter/Shoot.h"

ShooterSubsystem::ShooterSubsystem():
  Subsystem("ShooterSubsystem"),
  pivot(new Victor(PIVOT)),
  top_shooter(new Victor(TOP_SHOOTER)),
  bottom_shooter(new Victor(BOTTOM_SHOOTER)),
  top_roller(new Victor(TOP_ROLLER)),
  bottom_roller(new Victor(BOTTOM_ROLLER)),
  extension(new Victor(EXTENSION)),
  pivot_e(new VexEncoder(PIVOT_E)),
  extension_e(new VexEncoder(EXTENSION_E)),
  bottom_hardstop(new DigitalInput(BOTTOM_HARDSTOP)),
  top_shooter_e(new Encoder(TOP_SHOOTER_E, TOP_SHOOTER_E + 1)),
  bottom_shooter_e(new Encoder(BOTTOM_SHOOTER_E, TOP_SHOOTER_E + 1)),
  pivot_pid(new PIDController(0.01, 0.0, 0.01, pivot_e, pivot)),
  top_shooter_pid(new PIDController(0.01, 0.0, 0.01, top_shooter_e, top_shooter)),
  bottom_shooter_pid(new PIDController(0.01, 0.0, 0.01, bottom_shooter_e, bottom_shooter)),
  extension_pid(new PIDController(0.01, 0.0, 0.01, extension_e, extension))
{
  bottom_shooter->SetInverted(true);
  bottom_roller->SetInverted(true);
}

void ShooterSubsystem::InitDefaultCommand()
{
  // When no other commands are running, we do operator control
  SetDefaultCommand(new Shoot());
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
  bottom_roller->SetSpeed(speed);
}

void ShooterSubsystem::SetShooter(double speed) {
  top_shooter_pid->Enable();
  top_shooter_pid->SetSetpoint(speed);
  bottom_shooter_pid->Enable();
  bottom_shooter_pid->SetSetpoint(speed);
}

bool ShooterSubsystem::ShooterOnTarget() {
  return top_shooter_pid->OnTarget() && bottom_shooter_pid->OnTarget();
}

void ShooterSubsystem::SetExtension(double angle) {
  extension_pid->Enable();
  extension_pid->SetSetpoint(angle);
}
