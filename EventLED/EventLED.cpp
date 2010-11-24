#include "WProgram.h"
#include "EventLED.h"

EventLED::EventLED (int eventPin) {
  pinMode(eventPin, INPUT);
  _eventPin = eventPin;
  _lastEvent.event = none;
  _lastEvent.time  = -1;
  _lastValue;
  _valueInterval = 2;
  _timeInterval = 50;
  _maxValue     = 100;
  _minValue     = 0;
  _realValueInterval = map(_valueInterval, 0, 1024, _minValue, _maxValue);
}

void EventLED::onChange (Event event) { }

Event EventLED::getEvent() {
  unsigned long time = millis();
  return _lastEvent;
}
