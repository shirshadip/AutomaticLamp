int ldrPin = A0;
int redPin = 6;
int greenPin = 5;
int bluePin = 3;

int obstaclePin = 7;
int buzzerPin = 8;

bool buzzerOnDone = false;
bool buzzerOffDone = false;

void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(obstaclePin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int ldr = analogRead(ldrPin);   
  int obstacle = digitalRead(obstaclePin);

  bool lampOn = (ldr < 500 && obstacle == LOW);

  // ===== LAMP ON =====
  if (lampOn) {

    // COMMON ANODE → LOW = ON (kept same)
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);

    // 🔔 Beep ON (once)
    if (!buzzerOnDone) {
      tone(buzzerPin, 2000);
      delay(1000);
      noTone(buzzerPin);
      buzzerOnDone = true;
      buzzerOffDone = false;
    }
  }

  // ===== LAMP OFF =====
  else {

    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);

    // 🔔 Beep OFF (once)
    if (!buzzerOffDone) {
      tone(buzzerPin, 2000);
      delay(1000);
      noTone(buzzerPin);
      buzzerOffDone = true;
      buzzerOnDone = false;
    }
  }

  delay(300);
}
