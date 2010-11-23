#ifndef EVENTBUTTON_H
#define EVENTBUTTON_H

#include "WProgram.h"

const int none        = 0;
const int press       = 1;
const int unpress     = 2;
const int click       = 3;
const int holding     = 4;
const int hold        = 5;
const int dblclicking = 6;
const int dblclick    = 7;

typedef struct sEvent {
  int event;
  unsigned long time;
} Event;

class EventButton {
   public:
      EventButton (int eventPin);
      virtual void  onPress    ();
      //virtual void  onPressing ();
      virtual void  onUnpress  ();
      virtual void  onClick    ();
      virtual void  onDblClick ();
      virtual void  onHold     ();
      virtual void  onHolding  ();
      Event getEvent           ();
   private:
      Event _lastEvent;
      int   _eventPin;
};
#endif
