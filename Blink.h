#ifndef BLINK_H
#define BLINK_H
#include "Task.h"

class Blink : public Task {
  public:
     Blink(int pin, int initial, int period );
     virtual void run();
  private:
      int pin;
      int period;
      boolean state;
};
#endif
