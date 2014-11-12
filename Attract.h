#ifndef ATTRACT_H
#define ATTRACT_H

#include "Task.h"
#include "Topper.h"
#include "Led.h"

class Attract: public Task {

public:
	Attract(Topper* topper, Led* upperScoop, Led* lowerScoop);

	virtual void run();

private:
	int topperDelay;
	int state;

	Topper* topper;
	Led* upperScoop;
	Led* lowerScoop;

};

#endif

