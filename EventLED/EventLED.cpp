#include "WProgram.h"
#include "EventLED.h"

EventLED::EventLED (int eventPin) {
  pinMode(eventPin, OUTPUT);
  _eventPin = eventPin;
  _ledState = 0;
  digitalWrite(_eventPin, LOW);
  _blinkState = 0;
  _blinkingInterval = 1000;
}

void EventLED::getEvent() {
  unsigned long time = millis();
  if(_blinkState) {
    if(time - _lastBlink >= _blinkingInterval) {
      toggle();
      _lastBlink = time;
    }
  }
}

void  EventLED::onTurnOn     (){}
void  EventLED::onTurnOff    (){}
void  EventLED::onLight      (){}
void  EventLED::onDark       (){}
void  EventLED::onStartBlink (){}
void  EventLED::onStopBlink  (){}

void EventLED::turnOn ()       {
  _ledState = 1;
  digitalWrite(_eventPin, HIGH);
  onTurnOn();
}
void EventLED::turnOff()       {
  _ledState = 0;
  digitalWrite(_eventPin, LOW);
  onTurnOff();
}
void EventLED::toggle()        {
  if(_ledState) turnOff();
  else turnOn();
}
void EventLED::startBlinking() {
  _blinkState = 1;
  onStartBlink();
}
void EventLED::stopBlinking () {
  _blinkState = 0;
  onStopBlink();
}
void EventLED::blink(int sec) {
  unsigned long time = millis();
  onStartBlink();
  while(millis() - time < sec){
    toggle();
    delay(1000);
  }
  onStopBlink();
}
