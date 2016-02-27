#include <Commands/WaitTrigger.h>

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

