
#include "Led.h"

Led::Led(int offset) : 
Task( LED_MS ) {
    this->offset = offset;
    this->number = 1;
    this->switchOff();
}

Led::Led(int offset, int number) : 
Task( LED_MS ) {
    this->offset = offset;
    this->number = number;
    this->switchOff();
}

void Led::run() {
    if( this->actStep > 0 ) {
        for( int i = this->offset; i<this->offset+this->number; i++) {
            leds[i].r += this->dr;        
            leds[i].g += this->dg;        
            leds[i].b += this->db; 
        }
        FastLED.show();
        actStep--;
    }
}

void Led::fadeTo(int r, int g, int b, int steps ) {
    int i = this->offset;
    this->dr = ( r-leds[i].r ) / steps;
    this->dg = ( g-leds[i].g ) / steps;
    this->db = ( b-leds[i].b ) / steps;
    this->fadeSteps = steps;
    this->actStep = steps;
}

void Led::switchOff() {
    this->setColor(0,0,0);
}

void Led::setColor(int r, int g, int b) {
    for( int i = this->offset; i<this->offset+this->number; i++) {
        leds[i].r = r;        
        leds[i].g = g;        
        leds[i].b = b; 
    }
    FastLED.show();
}



