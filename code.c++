#include <Servo.h>

Servo gate;

int trigPin = 9;
int echoPin = 10;
int servoPin = 6;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  gate.attach(servoPin);
  gate.write(0); // Gate closed

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.println(distance);

  if (distance < 10) {   // Vehicle detected
    gate.write(90);      // Gate open
    delay(3000);
  } else {
    gate.write(0);       // Gate close
  }

  delay(500);
}
