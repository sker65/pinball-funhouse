
#include <FastLED.h>

#include "SoftTimer.h"

#include "Topper.h"
#include "Led.h"
#include "Attract.h"
#include "ScanSwitchedLamp.h"
#include "SwitchScanner.h"
#include "TogglePinAction.h"
#include "Blink.h"

// init fast led data struct for strip
#define NUM_LEDS 6
#define RGB_DATA_PIN 34
#define TOPPER1 30
#define TOPPER2 32
#define SMALL_LOWER_CLOWN 48
#define UPPER_LEFT_CLOWN 50
#define UPPER_RIGHT_CLOWN 52

CRGB leds[NUM_LEDS];

Blink b1(SMALL_LOWER_CLOWN, 1200, 1000);
Blink b2(UPPER_LEFT_CLOWN, 2500, 1200);
Blink b3(UPPER_RIGHT_CLOWN, 3800, 1400);


// create tasks for actors (lamps, topper, selenoids)
Topper topper( 300, TOPPER1, TOPPER2 );

Led upperScoop( 2, 4 );
Led lowerScoop( 0, 2 );

Attract attract( &topper, &upperScoop, &lowerScoop );

TogglePinAction clown1(50,true);

SwitchScanner switchScanner;

void interrupt() {
	switchScanner.readSwitches();
}

void setup() {

    // init strip
    FastLED.addLeds<NEOPIXEL, RGB_DATA_PIN>(leds, NUM_LEDS);
    
    // register tasks with scheduler
    SoftTimer.add( &topper );
    SoftTimer.add( &attract );
    SoftTimer.add( &upperScoop );
    SoftTimer.add( &lowerScoop );
    SoftTimer.add( &switchScanner );
    SoftTimer.add( &b1 );
    SoftTimer.add( &b2 );
    SoftTimer.add( &b3 );

    // let topper blink
    topper.setMode( blink50 );

    switchScanner.registerSwitchAction(2,1,&clown1);

    attachInterrupt(0, interrupt, FALLING);
    
    Serial.begin(9600);

}


