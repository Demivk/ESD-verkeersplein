//Led colours:         R   R   Y   Y   G  G
const int LEDPINS[] = {13, 12, 11, 10, 9, 8};
const int NUMBEROFLEDS = 6;

//[0] = left trafficlight
const int REDLEDS[] = {13, 12};
const int YELLOWLEDS[] = {11, 10};
const int GREENLEDS[] = {9, 8};

const int NUMBEROFCOLOURS = 3;
const int NUMBEROFTRAFFICLIGHTS = 2;
const int NUMBEROFSEQUENCES = 7;

int iTestLeds = 0;
int ledPatternInterval = 3000;

boolean ledStateYellow = false;

//Timers
unsigned long previousMillisLedPattern = 0;
unsigned long previousMillisBlinkYellow = 0;
unsigned long previousMillisTestLed = 0;
unsigned long previousMillisLight = 0;

//Led patterns
const int TRAFFICLIGHTLEFT[NUMBEROFCOLOURS][NUMBEROFLEDS] = {
  {0, 1, 0, 0, 1, 0},
  {0, 1, 1, 0, 0, 0},
  {1, 1, 0, 0, 0, 0}
};
const int TRAFFICLIGHTRIGHT[NUMBEROFCOLOURS][NUMBEROFLEDS] = {
  {1, 0, 0, 0, 0, 1},
  {1, 0, 0, 1, 0, 0},
  {1, 1, 0, 0, 0, 0}
};
const int TESTLEDSPATTERN[NUMBEROFSEQUENCES][NUMBEROFLEDS] = {
  {0, 0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0, 0},
  {1, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 1},
  {0, 0, 0, 0, 0, 0}
};

void ledSetup() {
  for (int i = 0; i < NUMBEROFLEDS; i++) {
    pinMode(LEDPINS[i], OUTPUT);
  }
  previousMillisLedPattern = millis();
  previousMillisBlinkYellow = millis();
  previousMillisTestLed = millis();
  previousMillisLight = millis();
}

void setLedsOn(int leds[], int numberOfLeds) {
  for (int i = 0; i < numberOfLeds; i++) {
    digitalWrite(leds[i], HIGH);
  }
}

void setLedsOff(int leds[], int numberOfLeds) {
  for (int i = 0; i < numberOfLeds; i++) {
    digitalWrite(leds[i], LOW);
  }
}

void trafficLightPattern(int pattern[][6]) {
  //if (millis() - previousMillisLedPattern >= ledPatternInterval) {
  //previousMillisLedPattern = millis();

  for (int i = 0; i < NUMBEROFCOLOURS; i++) {
    for (int j = 0; j < NUMBEROFLEDS; j++) {
      digitalWrite(LEDPINS[j], pattern[i][j]);
    }
    delay(3000);  //without delay
  }
  //}
}

void blinkYellowLeds() {
  if (millis() - previousMillisBlinkYellow >= 1000) {
    if (ledStateYellow) {
      setLedsOn(YELLOWLEDS, NUMBEROFTRAFFICLIGHTS);
    } else {
      setLedsOff(YELLOWLEDS, NUMBEROFTRAFFICLIGHTS);
    }
    ledStateYellow = !ledStateYellow;
    previousMillisBlinkYellow = millis();
  }
}

void testLeds() {
  //if (millis() - previousMillisTestLed >= 500) {
  for (int i = 0; i < NUMBEROFSEQUENCES; i++) {
    for (int j = 0; j < NUMBEROFLEDS; j++) {
      digitalWrite(LEDPINS[j], TESTLEDSPATTERN[i][j]);
    }
    //previousMillisTestLed = millis();
    delay(500);
  }
  //}
}


/*
  void trafficLight(int side) { //left = 0; right = 1;
    left:
    digitalWrtie(red[1], HIGH);
    digitalWrite(green[0], HIGH);
    delay(5000);
    digitalWrite(green[0], LOW);
    digitalWrite(yellow[0], HIGH);
    delay(2000);
    digitalWrite(yellow[0], LOW);

    right:
    digitalWrite(red[0], HIGH);
    digitalWrite(green[1], HIGH);
    delay(5000);
    digitalWrite(green[1], LOW);
    digitalWrite(yellow[1], HIGH);
    delay(2000);
    digitalWrite(yellow[1], LOW);
  }

  void setGreenOn(int side) { //left = 0, right = 1;
  digitalWrite(REDLEDS[side], LOW);
  digitalWrite(YELLOWLEDS[side], LOW);
  digitalWrite(GREENLEDS[side], HIGH);
  }

  void setYellowOn(int side) { //left = 0, right = 1;
  digitalWrite(REDLEDS[side], LOW);
  digitalWrite(YELLOWLEDS[side], HIGH);
  digitalWrite(GREENLEDS[side], LOW);
  }

  void setRedOn(int side) { //left = 0, right = 1;
  digitalWrite(REDLEDS[side], HIGH);
  digitalWrite(YELLOWLEDS[side], LOW);
  digitalWrite(GREENLEDS[side], LOW);
  }

  void trafficLight(int side) { //left = 0, right = 1;
  //  if (millis() - previousMillisLight >= 50) {
    setGreenOn(side);
  //  }
  if (millis() - previousMillisLight >= 3000 && digitalRead(GREENLEDS[side]) == HIGH) {
    previousMillisLight = millis();
    setYellowOn(side);
  }
  if (millis() - previousMillisLight >= 1000 && digitalRead(YELLOWLEDS[side]) == HIGH) {
    previousMillisLight = millis();
    setRedOn(side);
  }
  }
*/
