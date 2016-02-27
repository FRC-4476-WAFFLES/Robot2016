#include "WaitTrigger.h"
////////////////DISCRIPTION//////////////////
// waits for a button press to end.
WaitTrigger::WaitTrigger(Trigger* t) {
	trigger = t;
}

void WaitTrigger::Initialize() {}
void WaitTrigger::Execute() {}

bool WaitTrigger::IsFinished() {
	return trigger->Get();
}

void WaitTrigger::End() {}
void WaitTrigger::Interrupted() {}

