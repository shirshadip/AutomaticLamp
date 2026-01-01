int ldrPin = A0;
int pirPin = A1;   // PIR analog output

int redPin = 6;
int greenPin = 5;
int bluePin = 3;

int buzzerPin = 8;

bool lampState = false;
bool lastLampState = false;

void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int ldrValue = analogRead(ldrPin);  // 0–1023
  int pirValue = analogRead(pirPin);  // 0–1023

  // ---- Serial Debug ----
  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print(" | PIR: ");
  Serial.println(pirValue);

  // DARK + MOTION (PIR threshold)
  if (ldrValue < 500 && pirValue > 200) {
    lampState = true;
  } 
  else {
    lampState = false;
  }

  // ===== LIGHT ON =====
  if (lampState) {
    // COMMON ANODE → FULL ON
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);

    Serial.println("🚫 Light OFF (Bright / No Motion)");
  }
  // ===== LIGHT OFF =====
  else {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);

    
    Serial.println("💡 Light ON (Dark + Motion)");
  }

  // ===== BUZZER (state change only) =====
  if (lampState != lastLampState) {
    tone(buzzerPin, 2000);
    delay(300);
    noTone(buzzerPin);
    lastLampState = lampState;
  }

  delay(300);
}
