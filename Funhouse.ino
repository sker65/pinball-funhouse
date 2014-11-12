
#include <FastLED.h>

#include "SoftTimer.h"

#include "Topper.h"
#include "Led.h"
#include "Attract.h"
#include "ScanSwitchedLamp.h"

// init fast led data struct for strip
#define NUM_LEDS 6
#define RGB_DATA_PIN 28
#define TOPPER1 30
#define TOPPER2 32

CRGB leds[NUM_LEDS];

// create tasks for actors (lamps, topper, selenoids)
Topper topper( 300, TOPPER1, TOPPER2 );

Led upperScoop( 2, 4 );
Led lowerScoop( 0, 2 );

Attract attract( &topper, &upperScoop, &lowerScoop );

void setup() {

    // init strip
    FastLED.addLeds<NEOPIXEL, RGB_DATA_PIN>(leds, NUM_LEDS);
    
    // register tasks with scheduler
    SoftTimer.add( &topper );
    SoftTimer.add( &attract );
    SoftTimer.add( &upperScoop );
    SoftTimer.add( &lowerScoop );

    // let topper blink
    topper.setMode( blink50 );

}

