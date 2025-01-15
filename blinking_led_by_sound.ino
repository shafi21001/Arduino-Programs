const int soundSensorPin = A0;
const int ledPin = 11;
const int threshold = 900;
bool lastSoundLevel = 0;
bool ledState = false;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int soundLevel = analogRead(soundSensorPin);
  Serial.println(soundLevel);
  if (soundLevel > threshold && lastSoundLevel <= threshold) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState ? HIGH : LOW);
    Serial.println(ledState ? "LED ON" : "LED OFF");
    delay(500);
  }
  lastSoundLevel = soundLevel;
  delay(10);
}