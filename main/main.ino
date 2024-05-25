#define ZPIN 2
#define YPIN 14
#define XPIN 15

#define BUZZPIN 10

#define SWPIN 7

#define LIGHTPIN 16.

void setup() {
  pinMode(ZPIN, INPUT_PULLUP);
  pinMode(XPIN, INPUT);
  pinMode(YPIN, INPUT);
  pinMode(BUZZPIN, OUTPUT);
  pinMode(SWPIN, INPUT);
  pinMode(LIGHTPIN, INPUT);

  Serial.begin(19200); //  setup serial
}

void loop() {
  int x = analogRead(XPIN);
  int y = analogRead(YPIN);
  int z = digitalRead(ZPIN);
  int switchState = digitalRead(SWPIN);
  int photocellReading0 = analogRead(LIGHTPIN);

  if (photocellReading0 > 700){
    tone(BUZZPIN, 1000);
  }
  else{
    noTone(BUZZPIN);
  }
  
  Serial.println(photocellReading0);
  if (switchState == LOW) {
    // switch is closed
    Serial.println("Switch 1");
  } else if (switchState == HIGH) {
    // switch is open
    Serial.println("Switch 0");
  }
  Serial.print(x + String(" "));
  Serial.print(y + String(" "));
  Serial.println(z);
}
