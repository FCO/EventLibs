#ifndef EVENTLED_H
#define EVENTLED_H

#include "WProgram.h"

const int None        = 0;
const int Turnon      = 1;
const int Turnoff     = 2;
const int Toggle      = 2;
const int Light       = 3;
const int Dark        = 4;
const int Startblink  = 5;
const int Stopblink   = 6;

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
