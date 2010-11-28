#include <EventPotentiometer.h>

class Potentiometer : public EventPotentiometer {
  public:
     Potentiometer(int pin) : EventPotentiometer(pin){}
     void onChange() {
     }
};

Potentiometer pot(3);

void setup() {}
void loop() {
  pot.getEvent();
}
