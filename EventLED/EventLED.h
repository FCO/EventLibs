#ifndef EVENTLED_H
#define EVENTLED_H

#include "WProgram.h"

const int none        = 0;
const int turnon      = 1;
const int turnoff     = 2;
const int light       = 3;
const int dark        = 4;
const int startblink  = 5;
const int stopblink   = 6;

typedef struct sEvent {
  int event;
  unsigned long time;
} Event;

class EventLED {
   public:
      EventLED (int eventPin);
      virtual void  onTurnOn     (Event event);
      virtual void  onTurnOff    (Event event);
      virtual void  onLight      (Event event);
      virtual void  onDark       (Event event);
      virtual void  onStartBlink (Event event);
      virtual void  onStopBlink  (Event event);
      Event getEvent             ();
      void turnOn ();
      void turnOff();
      void startBlinking();
      void stopBlinking ();
      void blink(int msec);
   private:
      int   _eventPin;
      int   _ledState;
      int   _blinkState;
};
#endif
