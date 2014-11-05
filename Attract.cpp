#include "Attract.h"
#include "Led.h"

Attract::Attract(Topper* topper, Led* upperScoop, Led* lowerScoop ) : 
Task ( 100 ) {
    this->topper = topper;
    this->upperScoop = upperScoop;
    this->lowerScoop = lowerScoop;
    state = 0;
    topperDelay=200;
}

void Attract::run() {
    // switch "states" and ajust wait time
    switch(state) {
    case 0:
        upperScoop->fadeTo( 0,0,255,20);
        lowerScoop->fadeTo( 255,0,0,20);
        if( topperDelay == 200 ) {
          topperDelay = 400;
        } else {
          topperDelay = 200;
        }
        topper->setPeriodMs(topperDelay);
        topper->setMode(blink50);
        this->setPeriodMs( 10000 );
        break;
    case 1:
        upperScoop->fadeTo( 0,0,0,20);
        lowerScoop->fadeTo( 0,0,0,20);
        this->setPeriodMs( 23*LED_MS );
        break;
    case 2:
        upperScoop->fadeTo( 255,0,0,20);
        lowerScoop->fadeTo( 0,0,255,20);
        topper->setMode(off);
        this->setPeriodMs( 10000 );
        break;
    case 3:
        upperScoop->fadeTo( 0,0,0,20);
        lowerScoop->fadeTo( 0,0,0,20);
        topper->setMode(on);
        this->setPeriodMs( 23*LED_MS );
        this->state = -1; // loop 
        break;
    }
    state++;
}




