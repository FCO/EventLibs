#ifndef EVENTPOTENTIOMETER_H
#define EVENTPOTENTIOMETER_H

#include "WProgram.h"

const int none        = 0;
const int change      = 1;

typedef struct sEvent {
  int event;
  unsigned long time;
  int value;
} pEvent;

class EventPotentiometer {
   public:
      EventPotentiometer (int eventPin);
      virtual void  onChange   (pEvent event);
      pEvent getEvent          ();
      void setIntervalTime     (int);
      void setIntervalValue    (int);
   private:
      int   _maxValue;
      int   _minValue;
      int   _realValueInterval;
      pEvent _lastEvent;
      int   _lastValue;
      int   _valueInterval;
      int   _eventPin;
      unsigned long _timeInterval;
};
#endif
