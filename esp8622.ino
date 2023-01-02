#include <ArduinoWiFiServer.h>
#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiGratuitous.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>


#ifndef STASSID 
#define STASSID "Fadhila"
#define STAPSK "12345678000"
#endif


const char* ssid = STASSID ; 
const char* password =  STAPSK ; 

WiFiServer server(80);

void setup() { 
  // put your setup code here, to run once:
Serial.begin(115200);
delay(10);
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);//connexion
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected.");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
server.begin();//connexion
}


void loop() {
  // put your main code here, to run repeatedly:
WiFiClient client = server.available();
if (client) {
Serial.println("New Client.");
String currentLine = "";
while (client.connected()) {
if (client.available()) {
char c = client.read();
Serial.write(c);
client.println("HTTP/1.1 200 OK");
client.println("Content-type:text/html");
client.println();
client.print("<h1>Hello</h1>");
break;
} else { // if you got a newline, then clear currentLine:
currentLine = "";
}
}
}
// close the connection:
client.stop();//connexion


    
}