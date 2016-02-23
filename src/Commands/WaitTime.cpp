#include <Commands/WaitTime.h>

WaitTime::WaitTime(double duration) {
	this->timer = Timer();
	this->duration = duration;
}

void WaitTime::Initialize() {
	timer.Reset();
	timer.Start();
}

void WaitTime::Execute() {}

bool WaitTime::IsFinished() {
	return timer.Get() > duration;
}

void End() {}
void Interrupted() {}

