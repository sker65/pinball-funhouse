/*
 * TogglePinAction.h
 *
 *  Created on: 12.11.2014
 *      Author: srinke
 */

#ifndef TOGGLEPINACTION_H_
#define TOGGLEPINACTION_H_

#include "SwitchAction.h"

class TogglePinAction : public SwitchAction {
public:
	TogglePinAction(int pin, boolean highOnActive);
	void onSwitchActive();
	void onSwitchInactive();
private:
	int pin;
	boolean highOnActive;
};

#endif /* TOGGLEPINACTION_H_ */
