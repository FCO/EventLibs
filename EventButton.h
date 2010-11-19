#ifndef EventButton_h
#define EventButton_h

#include "WProgram.h"

const int none      = 0;
const int press     = 1;
const int unpress   = 2;
const int click     = 3;
const int holding   = 4;
const int hold      = 5;
const int dblclick  = 6;

typedef struct sEvent {
  int event;
  unsigned long time;
} Event;

class EventButton {
   public:
      EventButton (int eventPin);
      void  onPress    ();
      void  onUnpress  ();
      void  onClick    ();
      void  onDblClick ();
      void  onHold     ();
      void  onHolding  ();
      Event getEvent   ();
   private:
      Event _lastEvent;
      int   _eventPin;
};
#endif
