#include <AFMotor.h>
AF_DCMotor M2(2);
AF_DCMotor M3(3);
const int CS = A1;
const int RS = A0; 
const int LS = A2;
int R = 0;
int C = 0;
int L = 0;
int pos = 0;
boolean fire = false;
const int pump=A4;

void setup() {

M2.setSpeed(85);
M3.setSpeed(85);

pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
Serial.begin (9600);
}

 
void loop() {
C = digitalRead(CS);
R = digitalRead(RS);
L = digitalRead(LS);

if (L == 1 && C == 1 && R == 1){
  halt();
  }else if (C == 0 && R == 1 && L == 1){
    advance(); 
    }else if (R == 0 && C == 1 && L == 1 ){
    left();
    }else if (L == 0 && R == 1 && C == 1 ){
    right();
    }
delay(250);
while (fire == true);
{put_of_fire();
}

}
void advance()
{M2.run(FORWARD);
 M3.run(FORWARD);
 
}

void halt()
{M2.run(RELEASE);
 M3.run(RELEASE);

}

void right(){
  M2.run(RELEASE);
  M3.run(FORWARD);
  }

void left(){
  M2.run(FORWARD);
  M3.run(RELEASE);
  } 

void put_of_fire(){
  delay(500);
  halt();
  
  digitalWrite(pump,HIGH);
  delay(500);

  digitalWrite(pump,LOW);
  delay(500);
  fire=false;
  
  } 
