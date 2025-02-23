#include <Arduino.h>
#include "DabbleESP32.h"


char bleSignal;
int Speed = 255;
int enA = 5, enB = 23;
int IN1 = 22, IN2 = 21, IN3 = 19, IN4 = 18;
int enC = 32, enD = 14;
int IN5 = 33, IN6 = 25, IN7 = 26, IN8 = 27;
int buzzer = 4;


void setup() {
  Serial.begin(115200);
  Dabble.begin("NextGen ISSIG");


  ledcSetup(0, 5000, 8);
  ledcSetup(1, 5000, 8);
  ledcSetup(2, 5000, 8);
  ledcSetup(3, 5000, 8);
 
  ledcAttachPin(enA, 0);
  ledcAttachPin(enB, 1);
  ledcAttachPin(enC, 2);
  ledcAttachPin(enD, 3);


  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT); pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT); pinMode(IN8, OUTPUT);
  pinMode(buzzer, OUTPUT);


  powerUpBuzzer();
}


void loop() {
  Dabble.processInput();
  


  if (GamePad.isUpPressed()) forward();
  else if (GamePad.isDownPressed()) backward();
  else if (GamePad.isLeftPressed()) left();
  else if (GamePad.isRightPressed()) right();
  else stop();
}


void powerUpBuzzer() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
  }
}


void connectedBuzzer() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(300);
  }
}


void forward() {
  ledcWrite(0, Speed); ledcWrite(1, Speed);
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  ledcWrite(2, Speed); ledcWrite(3, Speed);
  digitalWrite(IN5, HIGH); digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW); digitalWrite(IN8, HIGH);
}


void backward() {
  ledcWrite(0, Speed); ledcWrite(1, Speed);
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  ledcWrite(2, Speed); ledcWrite(3, Speed);
  digitalWrite(IN5, LOW); digitalWrite(IN6, HIGH);
  digitalWrite(IN7, HIGH); digitalWrite(IN8, LOW);
}


void left() {
  ledcWrite(0, Speed); ledcWrite(1, Speed);
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  ledcWrite(2, Speed); ledcWrite(3, Speed);
  digitalWrite(IN5, HIGH); digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH); digitalWrite(IN8, LOW);
}


void right() {
  ledcWrite(0, Speed); ledcWrite(1, Speed);
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  ledcWrite(2, Speed); ledcWrite(3, Speed);
  digitalWrite(IN5, LOW); digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW); digitalWrite(IN8, HIGH);
}


void stop() {
  ledcWrite(0, 0); ledcWrite(1, 0);
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
  ledcWrite(2, 0); ledcWrite(3, 0);
  digitalWrite(IN5, LOW); digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW); digitalWrite(IN8, LOW);
}



