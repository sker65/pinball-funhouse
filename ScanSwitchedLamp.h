#ifndef SCANSWITCHEDLAMP_H
#define SCANSWITCHEDLAMP_H

#define SCAN_LAMP_MS 10

#include "Task.h"

/**
  *  scans a switched lamp and switched to false, if lamp is off for more than 30 ms
  */
class ScanSwitchedLamp : public Task {
    public:
        ScanSwitchedLamp( int pin );
        virtual void run();
        
        bool state;
        
    private:
        int pin;
        unsigned long lastTimeOn;
};

#endif
