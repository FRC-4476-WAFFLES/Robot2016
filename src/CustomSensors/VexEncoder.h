#pragma once

#include "WPILib.h"
#include "NonLoopingVexEncoder.h"

class VexEncoder: public SensorBase, public PIDSource {
private:
	DigitalInput input;
	Counter counter_high;
	Counter counter_low;

	float tearpoint;
	float last_int;
	float last_fract;

	bool first;
	bool error = false;
	int error_count = 0;
public:
	// Initialize a new sensor.
	VexEncoder(int port, float tearpoint = 0.0);

	// REVIEW: I'm not sure the counters can tolerate a move (since they are initialized as a pointer to the DigitalInput)
	VexEncoder(VexEncoder&&) = delete;

	// Get the angle (in degrees) that the sensor is reading. Does not account for continuous rotation.
	float GetRawAngle();

	// Gets the angle of the sensor taking the continuous rotation into account.
	float GetAngle();
	double PIDGet() override;

	// Reset the angle such that it is in its first rotation.
	void Reset();
	void prints();
};
