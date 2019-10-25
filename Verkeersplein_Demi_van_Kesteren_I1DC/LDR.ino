const int LDRPIN = A3;
const int LDRLIMIT = 550; //border value, used to decide if it is day or night; 550

void LDRSetup() {
  pinMode(LDRPIN, INPUT);
}

boolean isDay() {
  return (analogRead(LDRPIN) <= LDRLIMIT);
}

boolean isNight() {
  return (analogRead(LDRPIN) > LDRLIMIT);
}
