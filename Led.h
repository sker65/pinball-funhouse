#ifndef LED_H
#define LED_H

#include <FastLED.h>
#include "Task.h"

extern CRGB leds[];

#define LED_MS 30

/**
 * a task for controlling leds. leds are managed by fast led with is sharing one CRGB array.
 * this class represents one single led of such a strip or a section (offset, number)
 */
class Led : public Task {
public:
    Led( int offset );
    Led( int offset, int number );

    virtual void run();

    void switchOff();

    void setColor(int red, int green, int blue);

    void fadeTo( int red, int green, int blue, int steps );
    
private:
    int offset;
    int number;
    
    // fading
    int fadeSteps;
    int actStep;
    
    int dr, dg, db;
    
};

#endif

