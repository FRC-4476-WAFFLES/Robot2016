#include "WaitTrigger.h"

////////////////DISCRIPTION//////////////////
// Waits for a button to be pressed on the controller

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

