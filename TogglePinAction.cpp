/*
 * TogglePinAction.cpp
 *
 *  Created on: 12.11.2014
 *      Author: srinke
 */

#include <TogglePinAction.h>

#include <Arduino.h>

TogglePinAction::TogglePinAction(int pin, boolean highOnActive) {
	this->pin = pin;
	this->highOnActive = highOnActive;
	pinMode(pin, OUTPUT);
}

void TogglePinAction::onSwitchActive() {
	digitalWrite(pin,highOnActive?HIGH:LOW);
}

void TogglePinAction::onSwitchInactive() {
	digitalWrite(pin,highOnActive?LOW:HIGH);
}


