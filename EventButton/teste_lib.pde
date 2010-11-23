#include <EventButton.h>

const int ledPin    = 13;
const int alertPin  = 3;
const int buttonPin = 2;

class Button :public EventButton {
  public:
    Button() : EventButton(buttonPin) {ledState = 0;}
    void onClick () {
      if(ledState){
        digitalWrite(ledPin, LOW);
        ledState = 0;
      } else {
        digitalWrite(ledPin, HIGH);
        ledState = 1;
      }
    }
    void onHold () {
      for(int i = 0; i < 5; i++) {
        digitalWrite(ledPin, HIGH);
        delay(300);
        digitalWrite(ledPin, LOW);
        delay(300);
      }
      if(ledState) digitalWrite(ledPin, HIGH);
    }
    void onDblClick () {
      for(int i = 0; i < 3; i++) {
        digitalWrite(ledPin, HIGH);
        digitalWrite(alertPin, HIGH);
        delay(300);
        digitalWrite(ledPin, LOW);
        digitalWrite(alertPin, LOW);
        delay(300);
      }
      if(ledState) digitalWrite(ledPin, HIGH);
    }
    void onHolding () {
      digitalWrite(alertPin, HIGH);
    }
    void onUnpress () {
      digitalWrite(alertPin, LOW);
    }
    private:
      int ledState;
};

Button button;

void setup () {
  button = Button();
  pinMode(ledPin  , OUTPUT);
  pinMode(alertPin, OUTPUT);
}

void loop () {
  button.getEvent();
}

