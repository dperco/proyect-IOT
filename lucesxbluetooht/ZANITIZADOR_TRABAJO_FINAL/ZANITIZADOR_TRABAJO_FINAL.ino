#include<AFMotor.h>


AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

char bt='S';
int luz=13;
int infrarojo=8;
int valor=0;


void setup()
{
  Serial.begin(9600);
  pinMode(luz,OUTPUT);
  pinMode(infrarojo,INPUT);
  

  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor3.setSpeed(100);
  motor4.setSpeed(100);
  Stop();
  digitalWrite(luz,HIGH);
}


void loop() {


  valor = digitalRead(infrarojo);
  
  if (valor == LOW) {
     Serial.println("detectado");
  }

  

 
bt=Serial.read();

if(bt=='F')
{
 forward(); 
}

if(bt=='B')
{
 backward(); 
}

if(bt=='L')
{
 left(); 
}

if(bt=='R')
{
 right(); 
}

if(bt=='S')
{
 Stop(); 
}

if (bt == '5')   
    {
      digitalWrite(luz, LOW);  
    }
    if (bt == '6')   
    {
      digitalWrite(luz, HIGH); 
    }
}
void forward()
{
     motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void backward()
{
     motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void left()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void right()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void Stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
