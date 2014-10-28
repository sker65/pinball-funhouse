#include "ScanSwitchedLamp.h"
#include "Arduino.h"

ScanSwitchedLamp::ScanSwitchedLamp( int pin ) : 
Task( SCAN_LAMP_MS ) {
    this->pin = pin;
    this->state = false;
    pinMode( pin, INPUT );
}

void ScanSwitchedLamp::run() {
    unsigned long now = millis();
    // check when lamp was on the last time
    if( digitalRead( pin ) == HIGH ) {
        this->state = true;
        this->lastTimeOn = now;
    } 
    else {
        if( now - this->lastTimeOn > 30 ) {
            this->state = false;
        }
    }
}




