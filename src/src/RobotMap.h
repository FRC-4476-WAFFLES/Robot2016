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
constexpr int TOP_ROLLER = 4;//4or5
constexpr int BOTTOM_ROLLER = 5;//4or5
constexpr int TOP_SHOOTER = 6;
constexpr int BOTTOM_SHOOTER = 7;
constexpr int EXTENSION = 8;
constexpr int PIVOT = 9;

// Analog Inputs

// Relay
constexpr int SCALER_POSITION_LOCK = 0;
#warning "remember to set up bottom hardstop and pivot!!"
// Digital Inputs
constexpr int PIVOT_E = 4;//
constexpr int EXTENSION_E = 2;
constexpr int BOTTOM_HARDSTOP = 8;//
constexpr int TOP_SHOOTER_E = 2; // And 3
constexpr int DRIVE_ENCODER_A = 5;//
constexpr int DRIVE_ENCODER_B = 6;//
constexpr int BOTTOM_SHOOTER_E = 0; // And 1

#endif
