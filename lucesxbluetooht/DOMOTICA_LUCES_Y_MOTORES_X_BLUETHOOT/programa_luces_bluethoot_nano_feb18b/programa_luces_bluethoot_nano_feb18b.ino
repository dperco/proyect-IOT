/* Arduino Control House  By: http://www.elprofegarcia.com/
.... Contorl digital on/off del pin 13 al pin 6
.... Dimer de los Pin 3 y 5
.... Control de Servo por PIN 4
.... Lectura analoga del Puerto AO

Conexion del Modulo Bluetooth al Arduino 
usando Pin 0 y 1
Componentes conprados en la tienda: http://www.dinastiatecnologica.com/
*/

#include <Servo.h> 
Servo servo1;         // Crea el servo1 con las librerias de Servo.h

int estado=0;
int retardo=100;
int analogo=0;

void setup(){
  servo1.attach(4);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
  delay(1000);
 }
 void loop(){
 if(Serial.available()>0){           // Si el puerto serie esta habilitadp 
        estado = Serial.read();      // Lee lo que llega por el puerto Serie
 }
     
 if(estado== 'a'){                    // on/off de los pin 13 al pin 6
       digitalWrite(13,HIGH);
 }
 if(estado== 'b' ){
       digitalWrite(13,LOW);
 }
 if(estado== 'c'){ 
       digitalWrite(12,HIGH);
 }
 if(estado== 'd' ){
       digitalWrite(12,LOW);
 }
 if(estado== 'e'){ 
       digitalWrite(11,HIGH);
 }
 if(estado== 'f' ){
       digitalWrite(11,LOW);
 }
 if(estado== 'g' ){
       digitalWrite(10,HIGH);
 }
 if(estado== 'h' ){
       digitalWrite(10,LOW);
 }
 if(estado== 'i' ){
        digitalWrite(9,HIGH);
 }
 if(estado== 'j' ){
       digitalWrite(9,LOW);
      }
 if(estado== 'k' ){
        digitalWrite(8,HIGH);
 }
 if(estado== 'l' ){
      digitalWrite(8,LOW);
 }
 if(estado== 'm' ){
       digitalWrite(7,HIGH);
 }
 if(estado== 'n' ){
       digitalWrite(7,LOW);
 }
 if(estado== 'o' ){
      digitalWrite(6,HIGH);
 }
 if(estado== 'p' ){
       digitalWrite(6,LOW);
 }
 if(estado== 'A' ){      // Movimiento del SERVO
      servo1.write(0);  
      }
 if(estado== 'B' ){
      servo1.write(90); 
      }
 if(estado== 'C' ){
      servo1.write(180);  
      }
 
 if(estado=='s'){       //  Dimer 1 conectado al pin 5
        analogWrite(5,0);
       }
      
 if(estado=='t'){
        analogWrite(5,3);
       }   
if(estado=='u'){
        analogWrite(5,8);
       }  
if(estado=='v'){
        analogWrite(5,20);
       }  
if(estado=='w'){
        analogWrite(5,30);
       }  
if(estado=='x'){
        analogWrite(5,60);
       }  
if(estado=='y'){
        analogWrite(5,125);
       }  
if(estado=='z'){
        analogWrite(5,255);
       }         
       
       
 
 if(estado=='1'){               //  Dimer 2 conectado al pin 3
        analogWrite(3,0);
       }
      
 if(estado=='2'){
        analogWrite(3,3);
       }   
if(estado=='3'){
        analogWrite(3,8);
       }  
if(estado=='4'){
        analogWrite(3,20);
       }  
if(estado=='5'){
        analogWrite(3,30);
       }  
if(estado=='6'){
        analogWrite(3,60);
       }  
if(estado=='7'){
        analogWrite(3,125);
       }  
if(estado=='8'){
        analogWrite(3,255);
       }    
      
if(estado=='q'){         // envia el valor leido del puerto analogo A0
  analogo=analogRead(A0);
  Serial.print(analogo);
  Serial.println("∞C");
  delay (retardo);
  estado=0;
 }
 delay(retardo);
 }
 
 
