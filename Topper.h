#ifndef TOPPER_H
#define TOPPER_H

#include "Task.h"
/**
 * task that models the topper. the topper has two separate relays switches controlling 
 * 2 or 3 light bulbs resp. these relays are controlled by two arduino pins (see CTOR params).
 * topper supports 4 modes, off, on, blink50 and blink100
 */
enum TopperMode {
    off, blink50, blink100, on
};

class Topper : 
public Task {
public:

    Topper( unsigned long ms, int pin1, int pin2 );

    virtual void run();

    void switchOff();

    void setMode( TopperMode mode) { 
        this->mode = mode;   
    };

private:
    int pin1;
    int pin2;
    TopperMode mode;

};

#endif



