#include "Topper.h"

#include "Arduino.h"

Topper::Topper( unsigned long ms, int pin1, int pin2 ) : 
Task( ms ) {

    this->pin1 = pin1;
    this->pin2 = pin2;

    pinMode( pin1, OUTPUT );
    pinMode( pin2, OUTPUT );

    switchOff();

}

void Topper::run() {
    switch( this->mode ) {
    case off:
        switchOff();
        break;
    case on:
        digitalWrite( this->pin1, LOW );
        digitalWrite( this->pin2, LOW );
        break;
    case blink50:
        if( digitalRead( this->pin1) == LOW ) {
            digitalWrite( this->pin1, HIGH );
            digitalWrite( this->pin2, LOW );
        } 
        else {
            digitalWrite( this->pin1, LOW );
            digitalWrite( this->pin2, HIGH );
        }
        break;
    case blink100:
        if( digitalRead( this->pin1) == LOW ) {
            digitalWrite( this->pin1, HIGH );
            digitalWrite( this->pin2, HIGH );
        } 
        else {
            digitalWrite( this->pin1, LOW );
            digitalWrite( this->pin2, LOW );
        }
        break;
    }
}

void Topper::switchOff() {
    digitalWrite( this->pin1, HIGH );
    digitalWrite( this->pin2, HIGH );
}





