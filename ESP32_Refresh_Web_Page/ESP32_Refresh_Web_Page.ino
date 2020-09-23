/*
   Updates and Gets data from webpage without page refresh
*/
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

#include "index.h"  //Web page header file

WebServer server(80);

//Enter your SSID and PASSWORD
const char* ssid = "Talia";
const char* password = "12345678";

void handleRoot() {
  String s = MAIN_page; //Read HTML contents
  server.send(200, "text/html", s); //Send web page
}

int counter = 0;

void handleData() {
  counter++;
  String data_value = String(counter);
  server.send(200, "text/plane", data_value); //Send ADC value only to client request
}

//===============================================================
// Setup
//===============================================================

void setup(void) {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");

  /*
    //ESP32 As access point
    WiFi.mode(WIFI_AP); //Access Point mode
    WiFi.softAP(ssid, password);
  */
  //ESP32 connects to your wifi -----------------------------------
  //WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  //If connection successful show IP address in serial monitor
  
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.softAPIP());  //IP address assigned to your ESP
  
  //----------------------------------------------------------------

  server.on("/", handleRoot);      //This is display page
  server.on("/readData", handleData);//To get update of Data Value only

  server.begin();                  //Start server
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  delay(1);
}
