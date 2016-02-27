#include "Commands/DriveAuto.h"

DriveAuto::DriveAuto(double distance, double angle) {
	Requires(drive.get());
	this->distance = distance;
	this->angle = angle;
}

