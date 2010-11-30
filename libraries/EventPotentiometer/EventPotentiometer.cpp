#include "WProgram.h"
#include "EventPotentiometer.h"

EventPotentiometer::EventPotentiometer (int eventPin) {
  pinMode(eventPin, INPUT);
  _eventPin = eventPin;
  _lastEvent.event = none;
  _lastEvent.time  = -1;
  _lastValue;
  _valueInterval = 5;
  _timeInterval = 100;
  _maxValue     = 100;
  _minValue     = 0;
  _realValueInterval = _transformValue(_valueInterval);
}

void EventPotentiometer::onChange (pEvent event) { }

int EventPotentiometer::_transformValue(int value) {
  _lastEvent.value = map(value, 0, 1024, _minValue, _maxValue);
  return constrain(value, _minValue, _maxValue);
}

pEvent EventPotentiometer::getEvent() {
  unsigned long time = millis();
  int value = analogRead(_eventPin);
  if(time - _lastEvent.time > _timeInterval) {
    _lastEvent.time = time;
    if(abs(value - _lastEvent.value) > _realValueInterval) {
      _lastEvent.event = change;
      _lastEvent.value = _transformValue(value);
      onChange(_lastEvent);
    }
  }

  return _lastEvent;
}

void EventPotentiometer::setMinMax(int min, int max) {
  _minValue = min;
  _maxValue = max;
  _realValueInterval = _transformValue(_valueInterval);
}

void EventPotentiometer::setIntervalTime (int interval) {
   _timeInterval = interval;
}

void EventPotentiometer::setIntervalValue (int interval) {
   _valueInterval = interval;
  _realValueInterval = _transformValue(_valueInterval);
}
