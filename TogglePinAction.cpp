/*
 * TogglePinAction.cpp
 *
 *  Created on: 12.11.2014
 *      Author: srinke
 */

#include <Arduino.h>

#include "TogglePinAction.h"

TogglePinAction::TogglePinAction(int pin, boolean highOnActive) : SwitchAction() {
	this->pin = pin;
	this->highOnActive = highOnActive;
	pinMode(pin, OUTPUT);
}

void TogglePinAction::onSwitchActive() {
//    Serial.println("switch active");
	digitalWrite(pin,highOnActive?HIGH:LOW);
}

void TogglePinAction::onSwitchInactive() {
//  Serial.println("switch NOT active");
	digitalWrite(pin,highOnActive?LOW:HIGH);
}


