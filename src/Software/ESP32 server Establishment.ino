#include <WiFi.h>
#include <WebServer.h>

const char* ssid="";  // enter ssid here !! 
const char* password=""; // enter pw here !! 
const char* HTMLPage = R"rawliteral( ...... )rawliteral"; // enter frontend code here !! 

WebServer Server(80);

void setup(){
    Serial.begin(115200);
    Serial.println("ROSHAN WELCOMES YOU TO THIS ENVIRONMENTAL MONITOR");
    WiFi.begin(ssid,password);
    if (WiFi.status() != WL_CONNECTED ){
      Serial.println(" Couldn't Establish Wireless Connection ");
      while(1);
    }
    Serial.println("Wireless Connection Established Successfully.");
    Serial.println("/n");
    Serial.print("Use IP Address : " + WiFi.localIP());

    Server.begin();
    Server.on("/",[](){ 
      Server.send(200,"text/html",HTMLPage);
    });


}

void loop() {
  Server.handleClient();
}

