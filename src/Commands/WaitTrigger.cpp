#include <Commands/WaitTrigger.h>

WaitTrigger::WaitTrigger(Trigger* trigger) {
	this->trigger = trigger;
}

void WaitTrigger::Initialize() {}
void WaitTrigger::Execute() {}

bool WaitTrigger::IsFinished() {
	return trigger->Get();
}

void End() {}
void Interrupted() {}

