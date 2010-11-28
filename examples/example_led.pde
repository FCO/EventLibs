#include <EventLED.h>
    
EventLED led(13);
    
void setup () {
  led.startBlinking();
}
    
void loop () {
  led.getEvent();
}
