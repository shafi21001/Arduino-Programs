const int ledPin = 13; 

void setup() {
  pinMode(ledPin, OUTPUT); 
}

void loop() {
  // Increase brightness
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness); 
    delay(10); 
  }

  // Decrease brightness
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness); 
    delay(10); 
}
