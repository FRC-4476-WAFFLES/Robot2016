/**
 * Drives in a direction for a certain number of encoder tick
 */

#include "DriveRollerExtract.h"

DriveRollerExtract::DriveRollerExtract() {
	// We need the drive subsystem to not be doing anything else
	Requires(drive.get());

	t = new Timer();
}

void DriveRollerExtract::Initialize() {
	t->Reset();
	t->Start();
}

void DriveRollerExtract::Execute() {

	drive->Drive(0.2, 0.2);
	roller->Roll(1.0);
}


// Returns true when the distance is within 200 and the angle is within 5 degrees
bool DriveRollerExtract::IsFinished() {
	return t->Get() > 3.0;
}

// Stop the motors when this command ends
void DriveRollerExtract::End() {
	drive->Drive(0.0, 0.0);
}

// Stop the motors when this command is interrupted by another
void DriveRollerExtract::Interrupted() {
	drive->Drive(0.0, 0.0);
}
