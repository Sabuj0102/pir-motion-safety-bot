int pirPin = 2;       // PIR sensor output
int buzzerPin = 3;    // Buzzer
int pumpPin = 4;      // Pump (controlled by transistor)

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int motionDetected = digitalRead(pirPin);

  if (motionDetected == HIGH) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(pumpPin, HIGH);
    Serial.println("🚶 Motion detected! Activating system.");
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(pumpPin, LOW);
    Serial.println("🛑 No motion.");
  }

  delay(500);
}
