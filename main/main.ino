const int MOTOR_CONTROL_PIN = 3;
const unsigned long SECOND = 1000;
const unsigned long MINUTE = SECOND * 60;
const unsigned long HOUR = MINUTE * 60;

unsigned long previousClockMotor = 0;
const unsigned long MOTOR_ON_DURATION = 45 * SECOND;
const unsigned long MOTOR_ON_INTERVAL = 2 * HOUR - MOTOR_ON_DURATION;

int ledState = LOW;
unsigned long previousClockLed = 0;
const unsigned long LED_ON_OFF_INTERVAL = SECOND;

void setup() {
  pinMode(MOTOR_CONTROL_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(MOTOR_CONTROL_PIN, HIGH);
  delay(3 * SECOND);
  digitalWrite(MOTOR_CONTROL_PIN, LOW);
}

void loop() {
  unsigned long currentClock = millis();
  if (currentClock - previousClockLed >= LED_ON_OFF_INTERVAL) {    
    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    // set the LED with the ledState of the variable:
    digitalWrite(LED_BUILTIN, ledState);
    // save the last time you blinked the LED
    previousClockLed = currentClock;
  }
  if (currentClock - previousClockMotor >= MOTOR_ON_INTERVAL) {
    digitalWrite(MOTOR_CONTROL_PIN, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(MOTOR_ON_DURATION);
    digitalWrite(MOTOR_CONTROL_PIN, LOW);
    previousClockMotor = millis();
  }
}
