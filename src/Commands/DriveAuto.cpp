#include "Commands/DriveAuto.h"

DriveAuto::DriveAuto(double distance, double angle) {
	Requires(drive.get());
	this->distance = distance;
	this->angle = angle;
}

void DriveAuto::Initialize() {

}

void DriveAuto::Execute() {
	double distanceError = distance - drive->driveEncoder();
	if(distanceError > 1) {
		distanceError = 1.0;
	}
	if(distanceError < -1) {
		distanceError = -1.0;
	}
	double angleError = angle - drive->GetGyro();
	drive->Drive(-0.1*angleError + 0.5*distanceError, -0.1*angleError + 0.5*distanceError);
}

bool DriveAuto::IsFinished() {
	double distanceError = distance - drive->driveEncoder();
	double angleError = distance - drive->GetGyro();
	return distanceError < 200 && distanceError > -200 && angleError < 5.0 && angleError > -5.0;
}

void DriveAuto::End() {
	drive->Drive(0.0, 0.0);
}

void DriveAuto::Interrupted() {
	drive->Drive(0.0, 0.0);
}
