#include "WaitTime.h"

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

