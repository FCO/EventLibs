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
  if(_blinkState) stopBlinking();
  onTurnOn();
}
void EventLED::turnOff()       {
  _ledState = 0;
  digitalWrite(_eventPin, LOW);
  if(_blinkState) stopBlinking();
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
  sec = sec * 1000;
  unsigned long time = millis();
  onStartBlink();
  while(millis() - time < sec){
    toggle();
    delay(_blinkingInterval);
  }
  onStopBlink();
}
void EventLED::setInterval(int usec) {
  _blinkingInterval = usec;
}
int EventLED::getInterval() {
  return _blinkingInterval;
}
