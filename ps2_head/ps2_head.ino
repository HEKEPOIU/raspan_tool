
#define ZPIN 5
#define YPIN 16
#define XPIN 17

void setup() {
  pinMode(ZPIN, INPUT_PULLUP);
  pinMode(XPIN, INPUT);
  pinMode(YPIN, INPUT);
  Serial.begin(19200);           //  setup serial
}

void loop() {
  int x = analogRead(XPIN);
  int y = analogRead(YPIN);
  int z = digitalRead(ZPIN);
  Serial.print(x + String(" "));
  Serial.print(y + String(" "));
  Serial.println(z);
}
