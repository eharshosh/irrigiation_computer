const int MOTOR_CONTROL_PIN = 3;
const unsigned long SECOND = 1000;
const unsigned long MINUTE = SECOND * 60;
const unsigned long HOUR = MINUTE * 60;

const unsigned long MOTOR_ON_DURATION = 45 * SECOND;
const unsigned long MOTOR_ON_INTERVAL = 2 * HOUR - MOTOR_ON_DURATION;
unsigned long nextMotorToggleTime = 0;

int motorState = LOW;
int ledState = LOW;

unsigned long nextLedToggleTime = 0;
const unsigned long LED_ON_OFF_INTERVAL = SECOND;

void setup() {
  pinMode(MOTOR_CONTROL_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void toggleLed(unsigned long currentClock) {
  if (ledState == LOW) {
    ledState = HIGH;
  } else {
    ledState = LOW;
  }
  digitalWrite(LED_BUILTIN, ledState);
  nextLedToggleTime = currentClock + LED_ON_OFF_INTERVAL;
}

void toggleMotor(unsigned long currentClock) {
  if (motorState == LOW) {
    motorState = HIGH;
    nextMotorToggleTime = currentClock + MOTOR_ON_DURATION;
  } else {
    motorState = LOW;
    nextMotorToggleTime = currentClock + MOTOR_ON_INTERVAL;
  }
  digitalWrite(MOTOR_CONTROL_PIN, motorState);    
}

void loop() {
  unsigned long currentClock = millis();
  if (currentClock >= nextLedToggleTime) {    
    toggleLed(currentClock);
  }
  if (currentClock >= nextMotorToggleTime) {
    toggleMotor(currentClock);
  }
}
