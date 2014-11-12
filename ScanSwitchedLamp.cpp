#include "ScanSwitchedLamp.h"
#include "Arduino.h"

ScanSwitchedLamp::ScanSwitchedLamp( int p ) :
Task( SCAN_LAMP_MS ) {
    pin = p;
    state = false;
    lastTimeOn = 0;
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




