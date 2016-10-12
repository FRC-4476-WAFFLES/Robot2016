#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// PID Motors
constexpr int DRIVE_MOTOR_LEFT_FRONT = 0;
constexpr int DRIVE_MOTOR_LEFT_BACK = 1;
constexpr int DRIVE_MOTOR_RIGHT_FRONT = 2;
constexpr int DRIVE_MOTOR_RIGHT_BACK = 3;
constexpr int PIVOT = 4;
constexpr int TOP_SHOOTER = 5;
constexpr int BOTTOM_SHOOTER = 6;
constexpr int TOP_ROLLER = 7;
constexpr int BOTTOM_ROLLER = 8;
constexpr int EXTENSION = 9;

// Analog Inputs

// Relay
constexpr int SCALER_POSITION_LOCK = 0;

// Digital Inputs
constexpr int PIVOT_E = 0;
constexpr int EXTENSION_E = 1;
constexpr int BOTTOM_HARDSTOP = 2;
constexpr int TOP_SHOOTER_E = 3; // And 4
constexpr int DRIVE_ENCODER_A = 5;
constexpr int DRIVE_ENCODER_B = 6;
constexpr int BOTTOM_SHOOTER_E = 7; // And 8

#endif
