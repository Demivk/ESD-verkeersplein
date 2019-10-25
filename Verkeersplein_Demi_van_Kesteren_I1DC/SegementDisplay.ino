byte numberFont[] = {
  B00111111, //0
  B00000110, //1
  B01011011, //2
  B01001111, //3
  B01100110, //4
  B01101101, //5
  B01111101  //6  
};
const int NUMBEROFNUMBERS = 7;

int iSegment = NUMBEROFNUMBERS - 1;
boolean finishedCountDown = false;

//Signs: dot is on
byte walkSign = B10111111;      //0
byte stopSign = B11101101;      //S
byte warningSign = B11111111;   //8

void giveSign(byte sign) {
  setShiftRegister(sign);
}

void countDown() {
  if (millis() - previousMillisSegment >= 1000) {
    if (iSegment > 0) {
      setShiftRegister(numberFont[iSegment]);
      iSegment--;
    } else {
      setShiftRegister(numberFont[0]);
      finishedCountDown = true;
      iSegment = NUMBEROFNUMBERS - 1;
    }
    previousMillisSegment = millis();
  }
}
