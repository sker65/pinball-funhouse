/*
 * SwitchAction.h
 *
 *  Created on: 12.11.2014
 *      Author: srinke
 */

#ifndef SWITCHACTION_H_
#define SWITCHACTION_H_

class SwitchAction {
public:
	virtual void onSwitchActive() = 0;
	virtual void onSwitchInactive() = 0;
};



#endif /* SWITCHACTION_H_ */
