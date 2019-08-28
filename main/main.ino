const int controlPin = 3;
const unsigned long second = 1000;
const unsigned long minute = second * 60;
const unsigned long hour = minute * 60;

int ledState = LOW;

unsigned long previousMillis = 0;
unsigned long onDuration = 45 * second;
unsigned long onInterval = 2 * hour - onDuration;

unsigned long previousMillisLed = 0;
unsigned long ledOnOffInterval = second;

void setup() {
  pinMode(controlPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(controlPin, HIGH);
  delay(3 * second);
  digitalWrite(controlPin, LOW);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillisLed >= ledOnOffInterval) {
    // save the last time you blinked the LED
    previousMillisLed = currentMillis;
    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(LED_BUILTIN, ledState);
  }
  if (currentMillis - previousMillis >= onInterval) {
    digitalWrite(controlPin, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(onDuration);
    previousMillis = millis();
  }
  digitalWrite(controlPin, LOW);
}
