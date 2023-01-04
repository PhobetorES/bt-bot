#include<Ultrasonic.h>
#include <Servo.h>
Ultrasonic u = Ultrasonic(2, 3);
Servo s = Servo();
//Right Motor forward,backward,speed
int rmf = 13;
int rmb = 12;
int rms = 11;
//Left Motor forward,backward,speed
int lmf = 6;
int lmb = 7;
int lms = 5;
//lights
int red = 8;
int grn = 9;

//==================================================

void setup() {
  pinMode(red, OUTPUT);
  pinMode(grn, OUTPUT);
  pinMode(rms, OUTPUT);
  pinMode(rmb, OUTPUT);
  pinMode(rmf, OUTPUT);
  pinMode(lms, OUTPUT);
  pinMode(lmf, OUTPUT);
  pinMode(lmb, OUTPUT);

  s.attach(4); //servo motor signal
  Serial.begin(9600); //starts sonic sensor
}

  void Forward(){
    analogWrite(rms, 200);
    analogWrite(lms, 200);
    digitalWrite(rmf,HIGH);
    digitalWrite(lmf,HIGH);
    digitalWrite(rmb,LOW);
    digitalWrite(lmb,LOW);
    delay(500);
    digitalWrite(rmf,LOW);
    digitalWrite(lmf,LOW);
    digitalWrite(rmb,LOW);
    digitalWrite(lmb,LOW);
  }
  
  void Backward(){
    analogWrite(rms, 200);
    analogWrite(lms, 200);
    digitalWrite(rmb,HIGH);
    digitalWrite(lmb,HIGH);
    digitalWrite(rmf,LOW);
    digitalWrite(lmf,LOW);
    delay(500);
    digitalWrite(rmf,LOW);
    digitalWrite(lmf,LOW);
    digitalWrite(rmb,LOW);
    digitalWrite(lmb,LOW);  
  }
    
  void RightTurn(){
    analogWrite(rms, 200);
    analogWrite(lms, 200);
    digitalWrite(rmb,HIGH);
    digitalWrite(lmf,HIGH);
    digitalWrite(rmf,LOW);
    digitalWrite(lmb,LOW); 
    delay(500);
    digitalWrite(rmf,LOW);
    digitalWrite(lmf,LOW);
    digitalWrite(rmb,LOW);
    digitalWrite(lmb,LOW); 
  }
  
  void LeftTurn(){
    analogWrite(rms, 200);
    analogWrite(lms, 200);
    digitalWrite(rmf,HIGH);
    digitalWrite(lmb,HIGH);
    digitalWrite(rmb,LOW);
    digitalWrite(lmf,LOW);
    delay(500);
    digitalWrite(rmf,LOW);
    digitalWrite(lmf,LOW);
    digitalWrite(rmb,LOW);
    digitalWrite(lmb,LOW);  
  }

  void Red(){
    digitalWrite(red,HIGH);
    delay(500);
    digitalWrite(red,LOW);
  }
  void Green(){
    digitalWrite(grn,HIGH);
    delay(500);
    digitalWrite(grn,LOW);
  }

//===============================================
  
void loop() {
  int x = Serial.read();
  s.write(90);
  delay(200);
  int d = u.read(); //for taking sonic sensor distance

  if(x=='F' && d>15){ // && is a 
    Forward();
    Green();  
  }

  if(x=='B' && d>15){
    Backward();
    Green();  
  }

  if(x=='R' && d>15){
    RightTurn();
    Green();  
  }

  if(x=='R' && d>15){
    LeftTurn();
    Green();  
  }

  if(d<15){
    Red();  
  }
}
  
