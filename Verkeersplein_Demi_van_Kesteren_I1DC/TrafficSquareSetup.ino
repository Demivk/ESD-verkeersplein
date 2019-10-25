//States
const int TRAFFICSQUARESTATE_DAY = 1;
const int TRAFFICSQUARESTATE_NIGHT = 2;
const int TRAFFICSQUARESTATE_CARLEFT = 3;
const int TRAFFICSQUARESTATE_PEDESTRAIN = 4;
const int TRAFFICSQUARESTATE_CARRIGHT = 5;
const int TRAFFICSQUARESTATE_TEST = 6;

int currentState = 0;

//Timers
unsigned long lastCarLeft = 0;
unsigned long lastPedestrain = 0;
unsigned long lastCarRight = 0;
unsigned long lastTest = 0;

void trafficSquareSetup() {
  currentState = TRAFFICSQUARESTATE_DAY;
  day_Entry();
}

void trafficSquareLoop() {
  switch (currentState) {
    //Day mode
    case TRAFFICSQUARESTATE_DAY:
      day_Do();
      if (isNight()) {
        day_Exit();
        currentState = TRAFFICSQUARESTATE_NIGHT;
        night_Entry();
      }
      if (/*isCarLeftPressed()*//*lastButtonPressed*/currentButton == carButtonLeft) {
        day_Exit();
        currentState = TRAFFICSQUARESTATE_CARLEFT;
        lastCarLeft = millis();
        carLeft_Entry();
      }
      if (/*isPedestrainPressed()*//*lastButtonPressed*/currentButton == pedestrainButton) {
        day_Exit();
        currentState = TRAFFICSQUARESTATE_PEDESTRAIN;
        lastPedestrain = millis();
        pedestrain_Entry();
      }
      if (/*isCarRightPressed()*//*lastButtonPressed*/currentButton == carButtonRight) {
        day_Exit();
        currentState = TRAFFICSQUARESTATE_CARRIGHT;
        lastCarRight = millis();
        carRight_Entry();
      }
      if (/*isTestPressed()*//*lastButtonPressed*/currentButton == testButton) {
        day_Exit();
        currentState = TRAFFICSQUARESTATE_TEST;
        test_Entry();
      }
      break;
    // Night mode
    case TRAFFICSQUARESTATE_NIGHT:
      night_Do();
      if (isDay()) {
        night_Exit();
        currentState = TRAFFICSQUARESTATE_DAY;
        day_Entry();
      }
      break;
    //Car Left
    case TRAFFICSQUARESTATE_CARLEFT:
      buttonPressed = false;
      carLeft_Do();

      if (millis() - lastCarLeft >= 7500) {
        lastCarLeft = millis();
        carLeft_Exit();
        currentState = TRAFFICSQUARESTATE_DAY;
        day_Entry();
      }
      break;
    //Pedestrains
    case TRAFFICSQUARESTATE_PEDESTRAIN:
      buttonPressed = false;
      pedestrain_Do();
      
      if (millis() - lastPedestrain >= 11000) {
        lastPedestrain = millis();
        pedestrain_Exit();
        currentState = TRAFFICSQUARESTATE_DAY;
        day_Entry();
      }
      break;
    //Car Right
    case TRAFFICSQUARESTATE_CARRIGHT:
      buttonPressed = false;
      carRight_Do();

      if (millis() - lastCarRight >= 7500) {
        lastCarRight = millis();
        carRight_Exit();
        currentState = TRAFFICSQUARESTATE_DAY;
        day_Entry();
      }
      break;
    //Test
    case TRAFFICSQUARESTATE_TEST:
      buttonPressed = false;
      test_Do();

      if (millis() - lastTest >= 12000) {
        lastTest = millis();
        test_Exit();
        currentState = TRAFFICSQUARESTATE_DAY;
        day_Entry();
      }
      break;
  }
}
