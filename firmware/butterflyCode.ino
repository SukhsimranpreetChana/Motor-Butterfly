#include <ESP32Servo.h>

Servo leftServo;
Servo rightServo;

const int LEFT_PIN = 18;
const int RIGHT_PIN = 19;

const int MIN = 500;
const int MAX = 2500;

// Test values, will fix after testing servos
int leftUp = 900;
int rightUp = 900;

int flapAmount = 600;

int leftDown;
int rightDown;


//The states for the wings, will turn into a statemachine
enum WingState {
  IDLE,
  FLAPPING,
  QUICK_MOVEMENT
};

WingState state = IDLE;

float stateStartTime = 0;

void setup() {
  Serial.begin(115200);

  //Adding constraints so that the servo does dig into base

  leftServo.attach(LEFT_PIN, MIN, MAX);
  rightServo.attach(RIGHT_PIN, MIN, MAX);

  leftDown = constrain(leftUp + flapAmount, MIN, MAX);
  rightDown = constrain(rightUp - flapAmount, MIN, MAX);

  enterState(IDLE);
}

void loop() {
  updateStateMachine();
}


// State machine functions
void enterState(WingState newState) {
  state = newState;
  stateStartTime = millis();

  switch (state) {
    case IDLE:
      leftServo.writeMicroseconds(leftUp);
      rightServo.writeMicroseconds(rightUp);
      break;
    case FLAPPING:
      break;
    case QUICK_MOVEMENT:
      break;
  }
}

//I will change this to react to the microphone later, first need to test its values.
void updateStateMachine() {
  float timePassed = (float)(millis() - stateStartTime);

  switch (state) {
    case IDLE:
      leftServo.writeMicroseconds(leftUp);
      rightServo.writeMicroseconds(rightUp);

      if (timePassed > 3000) {
        enterState(FLAPPING);
      }
      break;

    case FLAPPING:
      moveWings(timePassed, 1200);

      if (timePassed > 8000) {
        enterState(QUICK_MOVEMENT);
      }
      break;

    case QUICK_MOVEMENT:
      moveWings(timePassed, 350);

      if (timePassed > 2000) {
        enterState(IDLE);
      }
      break;
  }
}

void moveWings(float timePassed, int flapSpeed) {
  // This makes the wings repeat
  int flapTime = timePassed % flapSpeed;

  // t goes from 0 to 1
  float t = (float)flapTime / flapSpeed;

  if (t < 0.5) {
    t = t * 2;
  } else {
    t = 2 - t * 2;
  }

  // Smoother movement, follows cos graph from 0 to 1, or down and up - Got AI to help with this
  float smoothT = 0.5 - 0.5 * cos(t * PI);

  int leftPosition = leftUp + (leftDown - leftUp) * smoothT;
  int rightPosition = rightUp + (rightDown - rightUp) * smoothT;

  leftServo.writeMicroseconds(leftPosition);
  rightServo.writeMicroseconds(rightPosition);
}