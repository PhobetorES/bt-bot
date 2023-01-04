#include <Ultrasonic.h>
#include <Servo.h>

Ultrasonic u = Ultrasonic(2,3);
Servo s = Servo();

void setup() {

s.attach(4);
Serial.begin(9600);

pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
 
}

void loop() {

int x = Serial.read();
int d = u.distanceRead();
Serial.println(d);

  analogWrite(10, 180);
  analogWrite(11, 180);
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  delay(5000); 
  analogWrite(10, 180);
  analogWrite(11, 180);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  delay(5000);
}
