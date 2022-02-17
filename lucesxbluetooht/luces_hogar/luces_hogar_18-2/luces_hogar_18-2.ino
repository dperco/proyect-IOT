//---Inicio del espaciopublicitario ;-)
//Más proyectos en http://www.rogerbit.com
//Suscribete en http://www.youtube.com/user/carlosvolt?sub_confirmation=1
//Grupo en Facebook https://www.facebook.com/groups/RogerBit/
//---Fin del espaciopublicitario ;-)
//declaración de variables

#include<SoftwareSerial.h>
SoftwareSerial Serial(30,31);
String cadena;
int luz1 = 12;

int ledstatus1 = 0; 

void setup () {
    // setea la velocidad del puerto serie a 9600
    Serial.begin(9600);
    pinMode(luz1,OUTPUT);
    
  digitalWrite(luz1, HIGH);
  
}

void loop () {
  //lee las cadenas de caracteres que ingresan al puerto serie
  if (Serial.available())  {
    cadena = String("");
    while (Serial.available()) {
      cadena = cadena + char(Serial.read());//Lee caracter por caracter y concatena a la variable cadena
      delay(1);
      
    }
    //Lee el estados de los pines 2 y 3 y se los asignas a las variables ledstatus 1 y ledstatus2
    ledstatus1 = digitalRead(luz1);
    
    Serial.println(cadena);//Muestra en el terminal serial la cadena obtenida
    
    //Pin 2 
    if (cadena == "luz1") {//compara el valor de la cadena obetinada
    if(ledstatus1==LOW){// si el valor en bajo enciende el pin 2
    digitalWrite(luz1, HIGH);
    }
    if(ledstatus1==HIGH){// de lo contrario lo apaga
    digitalWrite(luz1, LOW);
    }
    }
    
   }
  }
