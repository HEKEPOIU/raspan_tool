#define SWPIN 7

void setup() {
  pinMode(SWPIN, INPUT);

  Serial.begin(19200); //  setup serial
}

void loop() {
  int switchState = digitalRead(SWPIN);

  if (switchState == LOW) {
    // switch is closed
    Serial.println("Switch is Closed");
  } else if (switchState == HIGH) {
    // switch is open
    Serial.println("Switch is Open");
  }
}
