#define trigPin 9
#define echoPin 10
#define buzzerPin 5

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);
  if (duration == 0) {
    distance = -1;
  } else {
    distance = duration * 0.034 / 2;
  }
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance >= 5 && distance <= 100) {
    int beepFreq = map(distance, 20, 100, 2000, 500);
    int beepDelay = map(distance, 20, 100, 100, 600);
    tone(buzzerPin, beepFreq, beepDelay);
    delay(beepDelay * 1.5);
    noTone(buzzerPin);
  } else {
    noTone(buzzerPin);
  }

  delay(100);
}
