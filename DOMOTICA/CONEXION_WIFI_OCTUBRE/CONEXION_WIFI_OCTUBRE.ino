#include <ESP8266WiFi.h>

// Sustituir con datos de vuestra red
const char* ssid     = "Daniel";
const char* password = "daniel1965";
#define pinLed1 16
#define pinLed2 15

WiFiServer server(80);
 
void setup()
{
  Serial.begin(115200);
  delay(10);
  pinMode(pinLed1,OUTPUT);
  pinMode(pinLed2,OUTPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Conectando a:\t");
  Serial.println(ssid); 

  // Esperar a que nos conectemos
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(200);
   Serial.print('.');
  }

   // Start the server
  server.begin();
  Serial.println("Server started");
 

  // Mostrar mensaje de exito y dirección IP asignada
  Serial.println();
  Serial.print("Conectado a:\t");
  Serial.println(WiFi.SSID()); 
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
}



void loop() {

   // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

 
  
   // Match the request
 
  int value1 = LOW;
 
  
  if (request.indexOf("/LED1=ON") != -1)  {
    digitalWrite(pinLed1, HIGH);
    value1 = HIGH;
  }
  if (request.indexOf("/LED1=OFF") != -1)  {
    digitalWrite(pinLed1, LOW);
    value1 = LOW;
  }
  
 
// Set ledPin according to the request
//digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Led pin is now: ");
 
  if(value1 == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
 
  client.println("<br><br>");
  client.println("<a href=\"/LED1=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/LED1=OFF\"\"><button>Turn Off </button></a><br />");  
  client.println("<a href=\"/LED2=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/LED2=OFF\"\"><button>Turn Off </button></a><br />");
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
  
