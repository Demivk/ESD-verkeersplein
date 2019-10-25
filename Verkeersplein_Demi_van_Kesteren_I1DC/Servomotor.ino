const int SERVOPIN = 3;

int minimumServo = 0;
int maximumServo = 180;
int servoInterval = 20; //ms

int currentPosition = 0;

int iServoOpen = minimumServo;
int iServoClose = maximumServo;

int iServoTest = 0;
int increment = 1;

//Timer
unsigned long previousMillisServo = 0;

void servoSetup() {
  servo.attach(SERVOPIN);
  previousMillisServo = millis();
  servo.write(currentPosition);
}

void openGate() {
  if (millis() - previousMillisServo >= servoInterval) {
    if (currentPosition < maximumServo) {
      currentPosition++;
      servo.write(currentPosition);
      previousMillisServo = millis();
    }
  }
}

void closeGate() {
  if (millis() - previousMillisServo >= servoInterval) {
    if (currentPosition > minimumServo) {
      currentPosition--;
      servo.write(currentPosition);
      previousMillisServo = millis();
    }
  }
}

void testGate() {
  if (millis() - previousMillisServo >= servoInterval) {
    previousMillisServo = millis();
    iServoTest += increment;
    if (iServoTest > maximumServo || iServoTest < minimumServo) {
      increment *= -1;
    }
    servo.write(iServoTest);
  }
}
