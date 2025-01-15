const int lm35Pin = A0;
void setup() {
  Serial.begin(9600);
}
void loop() {
  int analogValue = analogRead(lm35Pin);
  Serial.println(analogValue);
  float voltage = analogValue * (5.0 / 16383.0);  // 14-bit ADC resolution conversion
  Serial.println(voltage);
  float temperatureC = voltage * 100.0; 
  Serial.println(String("Temperature: ") + temperatureC + " °C");
  delay(1000);
}