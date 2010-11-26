#include "WProgram.h"
#include "EventPotentiometer.h"

EventPotentiometer::EventPotentiometer (int eventPin) {
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

void EventPotentiometer::onChange (pEvent event) { }

pEvent EventPotentiometer::getEvent() {
  unsigned long time = millis();
  int value = analogRead(_eventPin);
  if(time - _lastEvent.time > _timeInterval) {
    _lastEvent.time = time;
    if(abs(value - _lastEvent.value) > _realValueInterval) {
      _lastEvent.event = change;
      _lastEvent.value = map(value, 0, 1024, _minValue, _maxValue};
      onChange(_lastEvent);
    }
  }

  return _lastEvent;
}
