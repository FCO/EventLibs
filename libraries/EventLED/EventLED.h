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
      void turnOn (int stopblink);
      void turnOff();
      void turnOff(int stopblink);
      void toggle();
      void toggle(int stopblink);
      void startBlinking();
      void stopBlinking ();
      void blink(int sec);
      void setInterval(int usec);
      int  getInterval();
   private:
      int   _eventPin;
      int   _ledState;
      int   _blinkState;
      int   _blinkingInterval;
      unsigned long _lastBlink;
};
#endif
