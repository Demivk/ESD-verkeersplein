/////////////////////////////////////////////
//                 Day                     //
/////////////////////////////////////////////

void day_Entry() {
  //Serial.println("Day entry");
  //nextButton = true;
  setLedsOn(YELLOWLEDS, NUMBEROFTRAFFICLIGHTS);
}

void day_Do() {
  //Serial.println("Day do");
  giveSign(stopSign);
  tickBuzzer(buzzerTickSlow);
  closeGate();
  if (servo.read() == minimumServo) {
    setLedsOff(YELLOWLEDS, NUMBEROFTRAFFICLIGHTS);
    setLedsOn(REDLEDS, NUMBEROFTRAFFICLIGHTS);
  } else {
    setLedsOn(YELLOWLEDS, NUMBEROFTRAFFICLIGHTS);
    setLedsOff(REDLEDS, NUMBEROFTRAFFICLIGHTS);
  }
  checkButtons();
}

void day_Exit() {
  //Serial.println("Day exit");
  putBuzzerOff();
  setLedsOff(YELLOWLEDS, NUMBEROFTRAFFICLIGHTS);
  setLedsOn(REDLEDS, NUMBEROFTRAFFICLIGHTS);
}

/////////////////////////////////////////////
//                Night                    //
/////////////////////////////////////////////

void night_Entry() {
  //Serial.println("Night entry");
  giveSign(stopSign);
}

void night_Do() {
  //Serial.println("Night do");
  tickBuzzer(buzzerTickSlow);
  openGate();
  if (servo.read() == maximumServo) {
    putBuzzerOff();
    giveSign(warningSign);
    setLedsOff(REDLEDS, NUMBEROFTRAFFICLIGHTS);
    blinkYellowLeds();
  }
}

void night_Exit() {
  //Serial.println("Night exit");
  setLedsOn(YELLOWLEDS, NUMBEROFTRAFFICLIGHTS);
}

/////////////////////////////////////////////
//              Car Left                   //
/////////////////////////////////////////////
void carLeft_Entry() {
  //Serial.println("Left entry");
  buttonPressed = false;
  currentButton = -1;
  giveSign(stopSign);
  trafficLightPattern(TRAFFICLIGHTLEFT);
  //trafficLight(0); //left = 0; right = 1;
}

void carLeft_Do() {
  //Serial.println("Left do");
  tickBuzzer(buzzerTickSlow);
  closeGate();
  checkButtons();
}

void carLeft_Exit() {
  //Serial.println("Left exit");
  putBuzzerOff();
}

/////////////////////////////////////////////
//             Pedestrains                 //
/////////////////////////////////////////////
void pedestrain_Entry() {
  //Serial.println("P entry");
  buttonPressed = false;
  currentButton = -1;
  giveSign(walkSign);
  setLedsOff(YELLOWLEDS, NUMBEROFTRAFFICLIGHTS);
  setLedsOn(REDLEDS, NUMBEROFTRAFFICLIGHTS);
}

void pedestrain_Do() {
  //Serial.println("P do");
  tickBuzzer(buzzerTickFast);
  openGate();
  if (servo.read() == maximumServo) {
    tickBuzzer(buzzerTickQuick);
    countDown();
    if (finishedCountDown) {
      giveSign(stopSign);
      tickBuzzer(buzzerTickSlow);
      closeGate();
      finishedCountDown = false;
    }
  }
}

void pedestrain_Exit() {
  //Serial.println("P exit");
}

/////////////////////////////////////////////
//              Car Right                  //
/////////////////////////////////////////////
void carRight_Entry() {
  //Serial.println("R entry");
  buttonPressed = false;
  currentButton = -1;
  giveSign(stopSign);
  trafficLightPattern(TRAFFICLIGHTRIGHT);
  //trafficLight(1); //left = 0; right = 1;
}

void carRight_Do() {
  //Serial.println("R do");
  tickBuzzer(buzzerTickSlow);
  closeGate();
  checkButtons();
}

void carRight_Exit() {
  //Serial.println("R exit");
  putBuzzerOff();
}

/////////////////////////////////////////////
//                 Test                    //
/////////////////////////////////////////////
void test_Entry() {
  //Serial.println("Test entry");
  buttonPressed = false;
  currentButton = -1;
}

void test_Do() {
  //Serial.println("Test do");
  tickBuzzer(buzzerTickQuick);
  //testLeds();
  testGate();
}

void test_Exit() {
  //Serial.println("Test exit");
  putBuzzerOff();
}
