#define carButtonLeft 2
#define pedestrainButton 14 //A0
#define carButtonRight 15   //A1
#define testButton 16       //A2

const int BUTTONPINS[] = {carButtonLeft, pedestrainButton, carButtonRight, testButton};
const int NUMBEROFBUTTONS = 4;

int buzzerTickSlow = 1000;
int buzzerTickQuick = 500;
int buzzerTickFast = 250;

int currentButton = -1;

//Save button state variables
//int buttonPressed[NUMBEROFBUTTONS];
//int lastButtonPressed = -1;
//boolean nextButton = true;

boolean buttonPressed = false;

void buttonSetup() {
  for (int i = 0; i < NUMBEROFBUTTONS; i++) {
    pinMode(BUTTONPINS[i], INPUT);
  }
}

void checkButtons() {
  if (!buttonPressed) {
    for (int i = 0; i < NUMBEROFBUTTONS; i++) {
      if (digitalRead(BUTTONPINS[i]) > 0) {
        currentButton = BUTTONPINS[i];
        buttonPressed = true;
      }
    }
  }
}

//Save button state
/*
boolean checkButtonPressed(int pin) {
  return(digitalRead(pin) == HIGH);
}

void clearButtonPressed() {
  for (int i = 0; i < NUMBEROFBUTTONS; i++) {
    buttonPressed[i] = 0;
  }
}

void overwriteLastButton() {
  lastButtonPressed = buttonPressed[0];
}

void nextButtonPressed() {
  if (nextButton) {
    for (int i = 0; i < NUMBEROFBUTTONS; i++) {
      if (i >= NUMBEROFBUTTONS) { //
        buttonPressed[i] = 0;
      } else {
        buttonPressed[i] = buttonPressed[i+1];
      }
    }
  }
  nextButton = false;
}

void addPressedButton(int button) {
  boolean exist = false;
  for (int i = 0; i < NUMBEROFBUTTONS; i++) {
    if (buttonPressed[i] == button) {
      exist = true;
    }
  }
  if (exist == false) {
    int emptySpot = NUMBEROFBUTTONS;

    for (int i = NUMBEROFBUTTONS - 1; i >= 0; i--) {
      if (buttonPressed[i] == 0) {
        emptySpot = i;
      }
    }
    if (emptySpot < NUMBEROFBUTTONS) {
      buttonPressed[emptySpot] = button;
    }
  }
}

void checkAllButtons() {
  for (int i = 0; i < NUMBEROFBUTTONS; i++) {
    if (checkButtonPressed(buttonPressed[i])) {
      addPressedButton(BUTTONPINS[i]);
    }
  }
}
*/

//Check buttons pressed
/*
boolean isCarLeftPressed() {
  if (buttonPressed) {
    return (currentButton == BUTTONPINS[0]);
  } else {
    return false;
  }
}

boolean isPedestrainPressed() {
  if (buttonPressed) {
    return (currentButton == BUTTONPINS[1]);
  } else {
    return false;
  }
}

boolean isCarRightPressed() {
  if (buttonPressed) {
    return (currentButton == BUTTONPINS[2]);
  } else {
    return false;
  }
}

boolean isTestPressed() {
  if (buttonPressed) {
    return (currentButton == BUTTONPINS[3]);
  } else {
    return false;
  }
}*/
