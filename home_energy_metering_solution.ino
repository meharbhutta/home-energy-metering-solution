#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const int BUTTON1 = 5;
const int BUTTON2 = 4;
const int BUTTON3 = 0;
const int BUTTON4 = 14;
const int BUTTON5 = 12;
const int BUTTON6 = 13;

int BUTTON1state = 0;
int BUTTON2state = 0;
int BUTTON3state = 0;
int BUTTON4state = 0;
int BUTTON5state = 0;
int BUTTON6state = 0;

int BUTTON1Pstate = 0;
int BUTTON2Pstate = 0;
int BUTTON3Pstate = 0;
int BUTTON4Pstate = 0;
int BUTTON5Pstate = 0;
int BUTTON6Pstate = 0;

char ssid[] = "WIFI SSID";
char password[] =  "WIFI Passsword";

char deviceID[] =  "Device ID From Portal After Registration";

String portal = "Address of the Server" //e.g http://192.168.10.5:88 without slash at the end
String path = "Path of the server address if any" //e.g /path?, Must start the path from slash
                                                  //Because we are sending get request to server
                                                  //with query parameters so there should be a 
                                                  //? mark at the end of the path
                                                  //Your server should accept four parameter
                                                  //Plz see sendRequest method at the bottom
                                                  //Incase of parameter

void setup() {
  
//  Serial.begin(115200);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  pinMode(BUTTON5, INPUT);
  pinMode(BUTTON6, INPUT);

  if (WiFi.status() == WL_CONNECTED) {
    WiFi.disconnect();
  }

  WiFi.begin(ssid, password);

//  Serial.print("Connecting");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
//    Serial.print(".");
  }
  
//  Serial.println();

//  Serial.print("Co/nnected, IP address: ");
//  Serial.println(WiFi.localIP());
  
}

void loop() {
  
  BUTTON1state = digitalRead(BUTTON1);
  BUTTON2state = digitalRead(BUTTON2);
  BUTTON3state = digitalRead(BUTTON3);
  BUTTON4state = digitalRead(BUTTON4);
  BUTTON5state = digitalRead(BUTTON5);
  BUTTON6state = digitalRead(BUTTON6);
  
  if (BUTTON1state != BUTTON1Pstate) {
      BUTTON1Pstate = BUTTON1state;
      String sw = "0";
      if (BUTTON1state == HIGH) {
//        Serial.println("BUTTON1state is 1");
        sw = "1";
      } else {
//        Serial.println("BUTTON1state is 0");
        sw = "0";
      }
      sendRequest(sw,"1");
   }

   if (BUTTON2state != BUTTON2Pstate) {
      BUTTON2Pstate = BUTTON2state;
      String sw = "0";
      if (BUTTON2state == HIGH) {
//        Serial.println("BUTTON2state is 1");
        sw = "1";
      } else {
//        Serial.println("BUTTON2state is 0");
        sw = "0";
      }
      sendRequest(sw,"2");
  }

   if (BUTTON3state != BUTTON3Pstate) {
      BUTTON3Pstate = BUTTON3state;
      String sw = "0";
      if (BUTTON3state == HIGH) {
//        Serial.println("BUTTON3state is 1");
        sw = "1";
      } else {
//        Serial.println("BUTTON3state is 0");
        sw = "0";
      }
      sendRequest(sw,"3");
  }

   if (BUTTON4state != BUTTON4Pstate) {
      BUTTON4Pstate = BUTTON4state;
      String sw = "0";
      if (BUTTON4state == HIGH) {
//        Serial.println("BUTTON4state is 1");
        sw = "1";
      } else {
//        Serial.println("BUTTON4state is 0");
        sw = "0";
      }
      sendRequest(sw,"4");
  }

   if (BUTTON5state != BUTTON5Pstate) {
      BUTTON5Pstate = BUTTON5state;
      String sw = "0";
      if (BUTTON5state == HIGH) {
//        Serial.println("BUTTON5state is 1");
        sw = "1";
      } else {
//        Serial.println("BUTTON5state is 0");
        sw = "0";
      }
      sendRequest(sw,"5");
  }

   if (BUTTON6state != BUTTON6Pstate) {
      BUTTON6Pstate = BUTTON6state;
      String sw = "0";
      if (BUTTON6state == HIGH) {
//        Serial.println("BUTTON6state is 1");
        sw = "1";
      } else {
//        Serial.println("BUTTON6state is 0");
        sw = "0";
      }
      sendRequest(sw,"6");
  }
  delay(1000);
}


void sendRequest(String sw, String relayPin) {
  if ((WiFi.status() == WL_CONNECTED)) { 
    
    HTTPClient http;
 
    http.begin(portal + path + "a="+ sw +"&b="+ relayPin +"&c="+ deviceID +"&d=2018-07-28%2015:35:14.513");
    
    int httpCode = http.GET();
 
    if (httpCode > 0) {
 
        String payload = http.getString();
//        Serial.println(httpCode);
//        Serial.println(payload);
        
    }
//    else {
//      
//      Serial.println("Error on HTTP request");
//      
//    }
 
    http.end();
    
  } 
//  else {
//
//    Serial.println("Not connected to wifi");
//    
//  }
}

