#ifndef EVENTLED_H
#define EVENTLED_H

#include "WProgram.h"

const int none        = 0;
const int turnon      = 1;
const int turnoff     = 2;
const int toggle      = 2;
const int light       = 3;
const int dark        = 4;
const int startblink  = 5;
const int stopblink   = 6;

class EventLED {
   public:
      EventLED (int eventPin);
      virtual void  onTurnOn     ();
      virtual void  onTurnOff    ();
      virtual void  onLight      ();
      virtual void  onDark       ();
      virtual void  onStartBlink ();
      virtual void  onStopBlink  ();
      void getEvent              ();
      void turnOn ();
      void turnOff();
      void toggle();
      void startBlinking();
      void stopBlinking ();
      void blink(int sec);
   private:
      int   _eventPin;
      int   _ledState;
      int   _blinkState;
      unsigned long _lastBlink;
};
#endif
