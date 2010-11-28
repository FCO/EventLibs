#include <EventButton.h>
#include <EventLED.h>

EventLED led(13);  // set led on pin 13
EventLED alert(3); // set led on pin 3

class Button : public EventButton {
  public:
  Button(int eventPin) : EventButton(eventPin) {} // creator
  void onClick() {   // set onClick event
    led.toggle();    // if the led is turned on it turns it off and vice-versa
  }
  void onHolding() { // runs while you press more than 3 seconds
    alert.startBlinking();
  }
  void onUnpress() {
    alert.turnOff();
  }
  void onHold() {
    led.blink(6);
  }
};
Button button(2);

void setup() {
  alert.setInterval(100);
  led.setInterval(500);
}
void loop() {
  led.getEvent();
  alert.getEvent();
  button.getEvent();
}
