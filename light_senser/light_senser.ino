#define LIGHTPIN 16

void setup() {
  pinMode(LIGHTPIN, INPUT);

  Serial.begin(19200); //  setup serial
}
int photocellPin0 = 0; // the cell and 10K pulldown are connected to a0
int photocellReading0; // the analog reading from the analog resistor divider
float Res0=10.0; // Resistance in the circuit of sensor 0 (KOhms)

void loop() {
  photocellReading0 = analogRead(LIGHTPIN); // Read the analogue pin
  float Vout0 = photocellReading0 * 0.0048828125;   // calculate the voltage
  int lux0 = 500 / (Res0 * ((5 - Vout0) / Vout0));   // calculate the Lux
  Serial.print(photocellReading0);
  Serial.print(
      "Luminosidad 0: "); // Print the measurement (in Lux units) in the screen
  Serial.print(lux0);
  Serial.print(" Lux\t");
  Serial.print("Voltage: "); // Print the calculated voltage returned to pin 0
  Serial.print(Vout0);
  Serial.print(" Volts\t");
  Serial.print("Output: ");
  Serial.print(photocellReading0);    // Print the measured level at pin 0
  Serial.print("Ligth conditions: "); // Print an approach to ligth conditions
  if (photocellReading0 < 10) {
    Serial.println(" - Dark");
  } else if (photocellReading0 < 200) {
    Serial.println(" - Dim");
  } else if (photocellReading0 < 500) {
    Serial.println(" - Light");
  } else if (photocellReading0 < 800) {
    Serial.println(" - Bright");
  } else {
    Serial.println(" - Very bright");
  }
  delay(1000);
}
