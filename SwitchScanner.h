/*
 * SwitchScanner.h
 *
 *  Created on: 12.11.2014
 *      Author: srinke
 */

#ifndef SWITCHSCANNER_H_
#define SWITCHSCANNER_H_

#include "Task.h"
#include "SwitchAction.h"
#include <Arduino.h>

class ActionEntry {
public:
	SwitchAction* action;
	int col;
	byte rowMask;
};

#define MAX_HANDLERS 5

class SwitchScanner : public Task {

public:
	SwitchScanner();

	/** will called from interrupt. do nothing that takes very long.*/
	void readSwitches();

	/** register handlers.*/
	void registerSwitchAction( int column, int row, SwitchAction* action );

	virtual void run();

private:
	volatile boolean colStrobe;

	// two times 8 byte for row returns
	// two arrays are used to detect changes
	volatile byte rows[2][8];
	// switches from 0 to 1 and back
	volatile int rowIndex;

	int handlerIndex;

	ActionEntry handlers[MAX_HANDLERS];

};


#endif /* SWITCHSCANNER_H_ */
