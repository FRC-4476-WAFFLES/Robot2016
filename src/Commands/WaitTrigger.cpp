#include <Commands/WaitTrigger.h>

WaitTrigger::WaitTrigger(int buttonIndex) {
	this->trigger = new JoystickButton(oi->operatorController, buttonIndex);
}

void WaitTrigger::Initialize() {}
void WaitTrigger::Execute() {}

bool WaitTrigger::IsFinished() {
	return trigger->Get();
}

void WaitTrigger::End() {}
void WaitTrigger::Interrupted() {}

