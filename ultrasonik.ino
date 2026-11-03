const int trigPin = 3;
const int echoPin = 2;
const int buzzer = 8;

const int ledBlue = 5;
const int ledRed = 4;
const int ledGreen = 6;

long durasi;
float jarak;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  durasi = pulseIn(echoPin, HIGH, 30000);

  digitalWrite(ledBlue, LOW);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, LOW);
  noTone(buzzer);

  if (durasi == 0) {
    Serial.println("Objek tidak terdeteksi");
  } else {
    jarak = durasi * 0.0343 / 2;

    Serial.print("Jarak objek: ");
    Serial.print(jarak);
    Serial.println(" cm");

    if (jarak > 20) {
      digitalWrite(ledGreen, HIGH);
    }
    else if (jarak > 10) {
      digitalWrite(ledBlue, HIGH);
    }
    else {
      digitalWrite(ledRed, HIGH);
      tone(buzzer, 1000);
    }
  }

  delay(100);
}