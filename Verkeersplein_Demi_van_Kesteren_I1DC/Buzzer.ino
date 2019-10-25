const int BUZZERPIN = 4;
const int BUZZERFREQUENCY = 500; //frequency in Hz, > 31 Hz
boolean buzzerState = false;
unsigned long previousMillisBuzzer = 0;

void buzzerSetup() {
  pinMode(BUZZERPIN, OUTPUT);
  previousMillisBuzzer = millis();
}

void putBuzzerOn() {
  tone(BUZZERPIN, BUZZERFREQUENCY);
}

void putBuzzerOff() {
  noTone(BUZZERPIN);
}

void tickBuzzer(int interval) {
  if (millis() - previousMillisBuzzer >= interval) {
    if (buzzerState) {
      putBuzzerOff();
    } else {
      putBuzzerOn();
    }
    buzzerState = !buzzerState;
    previousMillisBuzzer = millis();
  }
}
