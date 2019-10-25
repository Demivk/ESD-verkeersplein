const int DS = 5;
const int ST_CP = 6;
const int SH_CP = 7;

void setupShiftRegister() {
  pinMode(DS, OUTPUT);
  pinMode(ST_CP, OUTPUT);
  pinMode(SH_CP, OUTPUT);
}

void clearShiftRegister() {
  changeAllState(0);
}

void allOnShiftRegister() {
  changeAllState(1);
}

void setShiftRegister(byte pattern) {
  digitalWrite(ST_CP, 0);

  for (int i = 7; i >= 0; i--) {
    int state = isSet(pattern, i);
    digitalWrite(DS, state);
    shiftClockPulse();
  }
  storageClockPulse();
}

//------------------------------------------------------\\

void shiftClockPulse() {
  digitalWrite(SH_CP, 1);
  digitalWrite(SH_CP, 0);
}

void storageClockPulse() {
  digitalWrite(ST_CP, 1);
  digitalWrite(ST_CP, 0);
}

void changeAllState(int state) {
  digitalWrite(ST_CP, 0);

  for (int i = 0; i < 8; i++) {
    digitalWrite(DS, state);
    shiftClockPulse();
  }
  storageClockPulse();
}

int isSet(byte pattern, int bitNr) {
  if (pattern & (1 << bitNr)) {
    return 1;
  } else {
    return 0;
  }
}
