/* ESD Beroepsproduct Verkeersplein
    Naam: Demi van Kesteren
    Klas: I1DC
    Datum: 4 april 2018
    Docent: Richard Holleman
*/

#include <Servo.h>
Servo servo;

const int BAUD = 9600;

unsigned long previousMillisSegment = 0;

void setup() {
  Serial.begin(BAUD);
  trafficSquareSetup();

  setupShiftRegister();
  clearShiftRegister();

  buttonSetup();
  buzzerSetup();
  LDRSetup();
  ledSetup();
  servoSetup();
  
  previousMillisSegment = millis();
}

void loop() {
  //nextButtonPressed();
  //overwriteLastButton();
  trafficSquareLoop();
}
