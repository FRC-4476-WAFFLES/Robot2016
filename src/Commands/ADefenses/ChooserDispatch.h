/*
 * ChooserDispatch.h
 *
 *  Created on: Mar 5, 2016
 *      Author: ben
 */

#ifndef SRC_COMMANDS_ADEFENSES_CHOOSERDISPATCH_H_
#define SRC_COMMANDS_ADEFENSES_CHOOSERDISPATCH_H_

#include <CommandBase.h>

class ChooserDispatch: public CommandBase {
public:
	ChooserDispatch();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_ADEFENSES_CHOOSERDISPATCH_H_ */
