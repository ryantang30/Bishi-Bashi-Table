#include <Joystick.h>

Joystick_ Joystick;

int inputPins[12] = {2,3,4,5,6,7,8,20,10,14,15,16};
int lastButtonState[12];

void setup() {
  // Initialize Button Pins
  for (int i = 0;i<12;i++){
    pinMode(inputPins[i], INPUT_PULLUP);
  }
  Joystick.begin();
}


void loop() {
  for (int i = 0;i<12;i++){
    int currentButtonState = !digitalRead(inputPins[i]);
    if (currentButtonState != lastButtonState[i])
    {
      Joystick.setButton(i, currentButtonState);
      lastButtonState[i] = currentButtonState;
    }
  }
  delay(10);
}
