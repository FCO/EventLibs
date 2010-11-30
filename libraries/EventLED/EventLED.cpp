#include "WProgram.h"
#include "EventLED.h"

EventLED::EventLED (int eventPin) {
  pinMode(eventPin, OUTPUT);
  _eventPin = eventPin;
  _ledState = 0;
  digitalWrite(_eventPin, LOW);
  _blinkState = 0;
  _blinkingIntervalOn  = 1000;
  _blinkingIntervalOff = 1000;
}

void EventLED::getEvent() {
  unsigned long time = millis();
  if(_blinkOnce) {
    if(time >= _blinkOnce) {
      _lastBlink = time;
      _blinkOnce = 0;
      turnOff(0);
    }
  }
  else if(_blinkState) {
    if(time - _lastBlink >= _blinkingIntervalOff) {
      //toggle(0);
      //_lastBlink = time;
      blinkOnce(_blinkingIntervalOn);
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
void EventLED::turnOn (int stopblink)       {
  _ledState = 1;
  digitalWrite(_eventPin, HIGH);
  if(_blinkState && stopblink) stopBlinking();
  onTurnOn();
}
void EventLED::turnOff()       {
  _ledState = 0;
  digitalWrite(_eventPin, LOW);
  if(_blinkState) stopBlinking();
  onTurnOff();
}
void EventLED::turnOff(int stopblink)       {
  _ledState = 0;
  digitalWrite(_eventPin, LOW);
  if(_blinkState && stopblink) stopBlinking();
  onTurnOff();
}
void EventLED::toggle()        {
  if(_ledState) turnOff();
  else turnOn();
}
void EventLED::toggle(int stopblink)        {
  if(_ledState) turnOff(stopblink);
  else turnOn(stopblink);
}
void EventLED::startBlinking() {
  _blinkState = 1;
  onStartBlink();
}
void EventLED::stopBlinking () {
  _blinkState = 0;
  onStopBlink();
}
void EventLED::blink(int times) {
  onStartBlink();
  for(int i = 0; i < times; i++){
    blinkOnce(_blinkingIntervalOn);
    delay(_blinkingIntervalOff);
  }
  onStopBlink();
}
void EventLED::blinkOnce(int usec) {
  turnOn(0);
  _blinkOnce = millis() + usec;
}
void EventLED::setOnTime(int usec) {
  _blinkingIntervalOn = usec;
}
int EventLED::getOnTime() {
  return _blinkingIntervalOn;
}
void EventLED::setOffTime(int usec) {
  _blinkingIntervalOff = usec;
}
int EventLED::getOffTime() {
  return _blinkingIntervalOff;
}
