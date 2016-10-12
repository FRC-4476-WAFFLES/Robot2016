#ifndef SRC_CUSTOMSENSORS_VEXENCODER_H_
#define SRC_CUSTOMSENSORS_VEXENCODER_H_

#include "WPILib.h"

class VexEncoder: public SensorBase, public PIDSource {
private:
	Counter* counter;
	float lastInt;
	float lastFract;
	bool first;
public:
	// Initialize a new sensor.
	VexEncoder(int port);

	// Get the angle (in degrees) that the sensor is reading. Does not account for continuous rotation.
	float GetRawAngle();

	// Gets the angle of the sensor taking the continuous rotation into account.
	float GetAngle();
	double PIDGet() override;

	// Reset the angle such that it is in its first rotation.
	void Reset();
};

#endif /* SRC_CUSTOMSENSORS_VEXENCODER_H_ */
