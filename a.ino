#include <Servo.h>
Servo myservo;
int max[8]={134,132,134,137,137,135,140,140};
int min[8]={8,11,9,4,4,4,1,-9};
int real_time[8];
void setup() {
  Serial.begin(9600);
  pinMode(48,OUTPUT);
  pinMode(49,OUTPUT);
  pinMode(50,OUTPUT);
  pinMode(51,OUTPUT);
  pinMode(52,OUTPUT);
  pinMode(53,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  myservo.attach(5); 
}

int one_or_zero(int location){
   if(real_time[location]<=30) {
    Serial.print("   0   ");
    return 0;
   }
   if(real_time[location]>=100){
    Serial.print("   1   ");
    return 1;
   }
}

void loop() {
  byte now = B00000000;
  
  myservo.write(90);
 
  digitalWrite(48,LOW);
  digitalWrite(49,LOW);
  digitalWrite(50,LOW);
  digitalWrite(51,LOW);
  digitalWrite(52,LOW);
  digitalWrite(53,LOW);
  
  for(int i=0;i<8;i++)
  {
    real_time[i]=map(analogRead(i),min[i],max[i],0,200);
  }
  
  if(real_time[0]>=85) now = now | B10000000;
  if(real_time[1]>=85) now = now | B01000000;
  if(real_time[2]>=85) now = now | B00100000;
  if(real_time[3]>=85) now = now | B00010000;
  if(real_time[4]>=85) now = now | B00001000;
  if(real_time[5]>=85) now = now | B00000100;
  if(real_time[6]>=85) now = now | B00000010;
  if(real_time[7]>=85) now = now | B00000001;
  
  if(analogRead(9)>=150)
  {
  }
  else
  {
  if(now==B11111111)
  {
  analogWrite(3,0);
  analogWrite(4,0);
  delay(50);
  analogWrite(3,0);
  analogWrite(4,0);
  myservo.write(90);
  Serial.println(now,BIN);
  Serial.println("servo 90");
  Serial.println();
  delay(500);
  }
  else
  {
  if(now==B01111111)
  {
    analogWrite(3,170);
    analogWrite(4,0);
    myservo.write(165);
    Serial.println(now,BIN);
    Serial.println("servo 165");
    Serial.println();
    delay(50);
  }
  if(now==B00111111)
  {
    analogWrite(3,170);
    analogWrite(4,0);
    myservo.write(165);
    Serial.println(now,BIN);
    Serial.println("servo 165");
    Serial.println();
    delay(50);
  }
  if(now==B00011111)
  {
    analogWrite(3,170);
    analogWrite(4,0);
    myservo.write(165);
    Serial.println(now,BIN);
    Serial.println("servo 165");
    Serial.println();
    delay(50);
  }
  if(now==B00001111)
  {
    analogWrite(3,170);
    analogWrite(4,0);
    myservo.write(165);
    Serial.println(now,BIN);
    Serial.println("servo 165");
    Serial.println();
    delay(50);
  }
  if(now==B10001111)
  {
    analogWrite(3,170);
    analogWrite(4,0);
    myservo.write(165);
    Serial.println(now,BIN);
    Serial.println("servo 165");
    Serial.println();
    delay(50);
  }
  if(now==B11000111)
  {
    analogWrite(3,170);
    analogWrite(4,0);
    myservo.write(90);
    Serial.println(now,BIN);
    Serial.println("servo 90");
    Serial.println();
    delay(50);
  }
  if(now==B11100011)
  {
    analogWrite(3,170);
    analogWrite(4,0);
    myservo.write(90);
    Serial.println(now,BIN);
    Serial.println("servo 90");
    Serial.println();
    delay(50);
  }
  if(now==B11110001)
  {
    analogWrite(3,170);
    analogWrite(4,0);
    myservo.write(25);
    Serial.println(now,BIN);
    Serial.println("servo 25");
    Serial.println();
    delay(50);
  }
  if(now==B11110000)
  {
    analogWrite(3,170);
    analogWrite(4,0);
    myservo.write(25);
    Serial.println(now,BIN);
    Serial.println("servo 25");
    Serial.println();
    delay(50);
  }
  if(now==B11111000)
  {
    analogWrite(3,170);
    analogWrite(4,0);
    myservo.write(25);
    Serial.println(now,BIN);
    Serial.println("servo 25");
    Serial.println();
    delay(50);
  }
  if(now==B11111100)
  {
    analogWrite(3,170);
    analogWrite(4,0);
    myservo.write(25);
    Serial.println(now,BIN);
    Serial.println("servo 25");
    Serial.println();
    delay(50);
  }
  if(now==B11111110){
    analogWrite(3,170);
    analogWrite(4,0);
    myservo.write(25);
    Serial.println(now,BIN);
    Serial.println("servo 25");
    Serial.println();
    delay(50);
  }
  }
  }
 
}
