
int luz=12;
int estado=0;


void setup() {
  
  Serial.begin(9600);
  pinMode(luz,OUTPUT);
  
  

}

void loop() {
 
    digitalWrite(luz,HIGH);
    delay(1000);
  
    digitalWrite(luz,LOW);
    delay(1000);
  

}
