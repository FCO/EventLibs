#include "WProgram.h"
#include "EventLED.h"

EventLED::EventLED (int eventPin) {
  pinMode(eventPin, OUTPUT);
  _eventPin = eventPin;
  _lastEvent.event = none;
  _lastEvent.time  = -1;
  _ledState = 0;
  digitalWrite(_eventPin, LOW);
}

void EventLED::onChange (Event event) { }

void EventLED::getEvent() {
  unsigned long time = millis();
  if(_blinkState) {
    if(time - _lastBlink) {
      toggle();
      _lastBlink = time;
    }
  }
}

void  onTurnOn     (){}
void  onTurnOff    (){}
void  onLight      (){}
void  onDark       (){}
void  onStartBlink (){}
void  onStopBlink  (){}

void turnOn ()       {
  _ledState = 1;
  digitalWrite(_eventPin, HIGH);
  onTurnOn();
}
void turnOff()       {
  _ledState = 0;
  digitalWrite(_eventPin, LOW);
  onTurnOff();
}
void toggle()        {
  if(_ledState) turnOff();
  else turnOn();
}
void startBlinking() {
  _blinkState = 1;
  onStartBlink();
}
void stopBlinking () {
  _blinkState = 0;
  onStopBlink();
}
void blink(int sec) {
  unsigned long time = millis();
  onStartBlink();
  while(millis() - time < sec){
    toggle();
    delay(1000);
  }
  onStopBlink();
}
