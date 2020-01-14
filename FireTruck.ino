const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;
const int enA = 10;
const int enB = 11;
const int LS  = A0;
const int RS  = A1;
const int CS  = A2;
const int pump = 7;

int pos = 0;
boolean fire = false;

int C = 0;
int R = 0;
int L = 0;

void setup() {
  // put your setup code here, to run once:
pinMode (IN1,OUTPUT);
pinMode (IN2,OUTPUT);
pinMode (IN3,OUTPUT);
pinMode (IN4,OUTPUT);
pinMode (enA,OUTPUT);
pinMode (enB,OUTPUT);
pinMode (pump,OUTPUT);
pinMode (LS,INPUT);
pinMode (RS,INPUT);
pinMode (CS,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
C = digitalRead(CS);
R = digitalRead(RS);
L = digitalRead(LS);

if (L == 1 && C == 1 && R == 1){
  halt();
  }else if (C == 0){
    forward();
    }else if (L == 0){
    left();
    }else if (R == 0){
    right();
    }

}
void forward(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite (enA,80);
  analogWrite (enB,80);
  }

void backward(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite (enA,80);
  analogWrite (enB,80);
  }
void left(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite (enA,80);
  analogWrite (enB,80);
  }
void right(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite (enA,80);
  analogWrite (enB,80);
  }
void halt(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite (enA,0);
  analogWrite (enB,0);
  }
void put_of_fire(){
  delay (500);
    halt();
    
    digitalWrite(pump,HIGH);
    delay(500);
 
    digitalWrite(pump,LOW);
    delay(500);
    fire=false;
 
  }
