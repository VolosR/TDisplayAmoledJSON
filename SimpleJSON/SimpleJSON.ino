
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

HTTPClient http;
DynamicJsonDocument doc(1048);

String payload="";

const char* ssid     = "xxxxxx";
const char* password = "xxxxxx";


void getData()
{
 if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
     http.begin("https://ipapi.co/json/"); //Specify the URL
     int httpCode = http.GET();                                        //Make the request
    if (httpCode > 0) {
    payload = http.getString();
   deserializeJson(doc, payload);
   const char* ii=doc["country"];
   Serial.println(ii);
   }
    http.end(); //Free the resources
}}



void setup()
{
 Serial.begin(9600);
  
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
   }delay(1000);
}

void loop()
{ 
getData();
delay(40000);
}