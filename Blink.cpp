
#include <Arduino.h>
#include "Blink.h"

Blink::Blink(int pin, int initial, int period ) : Task(initial) {
  this->pin = pin;
  this->period = period;
  this->state = false;
  pinMode(pin, OUTPUT);
}

void Blink::run() {
  setPeriodMs(this->period);
  digitalWrite(pin,state);
  state = !state;
}
