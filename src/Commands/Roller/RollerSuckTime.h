/*
 * RollerSuckTime.h
 *
 *  Created on: Mar 6, 2016
 *      Author: WAFFLES_Guest
 */

#ifndef SRC_COMMANDS_ROLLER_ROLLERSUCKTIME_H_
#define SRC_COMMANDS_ROLLER_ROLLERSUCKTIME_H_

#include <CommandBase.h>

class RollerSuckTime: public CommandBase {
private:
	Timer* timer;
	double time;
public:
	RollerSuckTime(double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_ROLLER_ROLLERSUCKTIME_H_ */
