#include "WaitTime.h"
////////////////DISCRIPTION//////////////////
// waits a certain amount of time that is specified when used.
WaitTime::WaitTime(double duration) {
	this->timer = new Timer();
	this->duration = duration;
}

void WaitTime::Initialize() {
	timer->Reset();
	timer->Start();
}

void WaitTime::Execute() {}

bool WaitTime::IsFinished() {
	return timer->Get() > duration;
}

void WaitTime::End() {}
void WaitTime::Interrupted() {}

