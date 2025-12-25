int ldrPin = A0;
int bluePin = 2;
int greenPin = 3;
int redPin = 4;

void setup() {
  Serial.begin(9600);
  analogReadResolution(10);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int ldr = analogRead(ldrPin);
  delay(300);

  if (ldr < 900) {   // DARK
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);
  Serial.println("Dark → Light is off");
} else {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  Serial.println("Bright → Light on");
}

}
