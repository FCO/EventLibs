#include "WProgram.h"
#include "EventButton.h"

EventButton::EventButton (int eventPin) {
  Serial.begin(9600);
  pinMode(eventPin, INPUT);
  _eventPin = eventPin;
}

void EventButton::onPress () {
  Serial.write("onPress\n");
}

void EventButton::onUnpress () {
  Serial.write("onUnpress\n");
}

void EventButton::onClick() {
  Serial.write("onClick\n");
}

void EventButton::onDblClick () {
  Serial.write("onDblClick\n");
}

void EventButton::onHold () {
  Serial.write("onHold\n");
}

void EventButton::onHolding () {
  Serial.write("onHolding\n");
}

Event EventButton::getEvent() {
  
  int buttonState = digitalRead(_eventPin);

  if(_lastEvent.event == press) {
    if(buttonState == HIGH) {
      if(millis() - _lastEvent.time >= 2000) {
        _lastEvent.event = holding;
        onHolding();
      }
    } else {
      onUnpress();
      _lastEvent.event = click;
      onClick();
    }
  }else if(_lastEvent.event == holding) {
    if(buttonState == LOW) {
      onUnpress();
      _lastEvent.event = hold;
      _lastEvent.time = -1;
      onHold();
    }
  } else if(buttonState == HIGH) {
    _lastEvent.time = millis();
    _lastEvent.event = press;
    onPress();
  }

  return _lastEvent;
}
