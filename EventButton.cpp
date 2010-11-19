#include "WProgram.h"
#include "EventButton.h"

EventButton::EventButton (int eventPin) {
  pinMode(eventPin, INPUT);
  _eventPin = eventPin;
  _lastEvent.event = none;
  _lastEvent.time  = -1;
}

void EventButton::onPress () { }
void EventButton::onUnpress () { }
void EventButton::onClick() { }
void EventButton::onDblClick () { }
void EventButton::onHold () { }
void EventButton::onHolding () { }

Event EventButton::getEvent() {
  unsigned long time = millis();
  int buttonState = digitalRead(_eventPin);

  if(_lastEvent.event == press) {
    if(buttonState == HIGH) {
      if(time - _lastEvent.time >= 2000) {
        _lastEvent.event = holding;
        onHolding();
      }
    } else {
      _lastEvent.event = unpress;
      onUnpress();
      //_lastEvent.event = click;
      //onClick();
    }
  }else if(_lastEvent.event == holding) {
    if(buttonState == LOW) {
      onUnpress();
      _lastEvent.event = hold;
      _lastEvent.time = -1;
      onHold();
    }
  } else if(_lastEvent.event == unpress) {
    if(buttonState == LOW && time - _lastEvent.time > 300) {
      _lastEvent.event = click;
      onClick();
    } else if(buttonState == HIGH && time - _lastEvent.time < 300){
      _lastEvent.event = dblclicking;
    }
  } else if(_lastEvent.event == dblclicking) {
    if(buttonState == LOW) {
      _lastEvent.event = dblclick;
      onDblClick();
    }
  } else if(buttonState == HIGH) {
    _lastEvent.time = time;
    _lastEvent.event = press;
    onPress();
  }

  return _lastEvent;
}
