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
const int DRIVE_MOTOR_LEFT_FRONT = 0;
const int DRIVE_MOTOR_LEFT_BACK = 1;
const int DRIVE_MOTOR_RIGHT_FRONT = 2;
const int DRIVE_MOTOR_RIGHT_BACK = 3;
const int SCALER_CLIMB_1 = 4;
const int SCALER_CLIMB_2 = 5;
const int SCALER_DEPLOYER = 6;
const int INTAKE_MOTOR_ARM = 7;
const int ROLLER_MOTOR = 8;
const int A_DEFENSES_MOTOR = 9;

// Analog Inputs

//Relay
const int SCALER_POSITION_LOCK = 0;

// Digital Inputs
const int INTAKE_ENCODER = 0;
const int INTAKE_RETRACTED_SWITCH = 1;
const int A_DEFENSES_POT = 2;
const int SCALER_CLIMB_ENCODER_A = 3;
const int SCALER_CLIMB_ENCODER_B = 4;
const int SCALER_DEPLOY_ENCODER_A = 5;
const int SCALER_DEPLOY_ENCODER_B = 6;
//calibrate section
const int INTAKE_MINIMUM_DISTANCE = 120;
#endif
