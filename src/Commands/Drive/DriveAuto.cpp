/**
 * Drives in a direction for a certain number of encoder tick
 */

#include "DriveAuto.h"

DriveAuto::DriveAuto(double distance, double angle) {
	// We need the drive subsystem to not be doing anything else
	Requires(drive.get());

	// Remember distance and angle for later
	this->distance = distance;
	this->angle = angle;
}

void DriveAuto::Initialize() {

}

void DriveAuto::Execute() {
	// Calculate the error on the distance traveled
	double distanceError = distance - drive->driveEncoder();

	// Make sure the distance error does not exceed 100%
	if(distanceError > 1) {
		distanceError = 1.0;
	}
	if(distanceError < -1) {
		distanceError = -1.0;
	}

	// Calculate the difference between the current angle and the desired angle
	double angleError = angle - drive->GetGyro();

	// Set the motors to run
	drive->Drive(-0.1*angleError + 0.5*distanceError, -0.1*angleError + 0.5*distanceError);
}

// Returns true when the distance is within 200 and the angle is within 5 degrees
bool DriveAuto::IsFinished() {
	double distanceError = distance - drive->driveEncoder();
	double angleError = angle - drive->GetGyro();
	return distanceError < 200 && distanceError > -200 && angleError < 5.0 && angleError > -5.0;
}

// Stop the motors when this command ends
void DriveAuto::End() {
	drive->Drive(0.0, 0.0);
}

// Stop the motors when this command is interrupted by another
void DriveAuto::Interrupted() {
	drive->Drive(0.0, 0.0);
}
