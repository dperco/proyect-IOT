


#define BLYNK_PRINT SERIAL
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>

char auth[]="7YihRL3Z4GJ2lbdKIn-b22800qJYKJJl"

char ssid[]="Daniel5"
char pass[]="daniel1965"

void setup() {
  
  Serial.begin (9600);
  Blynk.begin(auth,ssid,pass);
}

void loop() {
  
   Blynk.run();
}
