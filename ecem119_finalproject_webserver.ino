/*
  WiFi Web Server LED Blink

  A simple web server that lets you blink an LED via the web.
  This sketch will create a new access point (with no password).
  It will then launch a new server and print out the IP address
  to the Serial Monitor. From there, you can open that address in a web browser
  to turn on and off the LED on pin 13.

  If the IP address of your board is yourAddress:
    http://yourAddress/H turns the LED on
    http://yourAddress/L turns it off

  created 25 Nov 2012
  by Tom Igoe
  adapted to WiFi AP by Adafruit
 */

#include <SPI.h>
#include <WiFiNINA.h>
#include <iostream> 
#include <fstream> 
#include "homepagehtml.h"
#include "stylescss.h"

using namespace std;  


///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = "cocktail";        // your network SSID (name)
char pass[] = "12345678";    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;                // your network key index number (needed only for WEP)

int led =  LED_BUILTIN;
int status = WL_IDLE_STATUS;
WiFiServer server(80);

float time_connected = 0; 

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
//  while (!Serial) {
//    ; // wait for serial port to connect. Needed for native USB port only
//  }

  Serial.println("Access Point Web Server");

  pinMode(led, OUTPUT);      // set the LED pin mode

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }

  // by default the local IP address will be 192.168.4.1
  // you can override it with the following:
  // WiFi.config(IPAddress(10, 0, 0, 1));

  // print the network name (SSID);
  Serial.print("Creating access point named: ");
  Serial.println(ssid);

  // Create open network. Change this line if you want to create an WEP network:
  status = WiFi.beginAP(ssid, pass);  
  if (status != WL_AP_LISTENING) {
    Serial.println("Creating access point failed");
    // don't continue
    while (true);
  }

  // wait 10 seconds for connection:
  delay(10000);

  // start the web server on port 80
  server.begin();

  // you're connected now, so print out the status
  printWiFiStatus();

  //Open the .html and .css files 

  std::string homepage = indexhtml; 
//  Serial.println(homepage.c_str()); 
  std::string css = stylescss; 
//  Serial.println(stylescss.c_str()); 

}


void loop() {
  // compare the previous status to the current status
  if (status != WiFi.status()) {
    // it has changed update the variable
    status = WiFi.status();

    if (status == WL_AP_CONNECTED) {
      // a device has connected to the AP
      Serial.println("Device connected to AP");
    } else {
      // a device has disconnected from the AP, and we are back in listening mode
      Serial.println("Device disconnected from AP");
    }
  }
 
  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) 
    {            // loop while the client's connected
      delayMicroseconds(10);                // This is required for the Arduino Nano RP2040 Connect - otherwise it will loop so fast that SPI will never be served.
      if (client.available()) 
      {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out to the serial monitor
        if (c == '\n') 
        {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) 
          {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: Keep-Alive"); 
            client.println("Set-Cookie: userid=someuserid"); 
            client.println();

            // the content of the HTTP response follows the header:

             client.print(indexhtml.c_str()); 
//            client.print("You have visited the page " + String(time_connected) + " times<br>"); 
//            client.print("Click <a href=\"/H\">here</a> turn the LED on<br>");
//            client.print("Click <a href=\"/L\">here</a> turn the LED off<br>");
//            client.print("Click <a href=\"/1-1-1-1\">here</a> for drink 1<br>");
//            client.print("Click <a href=\"/1-2-3-4\">here</a> for drink 2<br>");
//            client.print("Click <a href=\"/3-3-4-4\">here</a> for drink 3<br>");
//            client.print("Click <a href=\"/2-2-3-4\">here</a> for drink 4<br>");

            // The HTTP response ends with another blank line:
            client.println();
            time_connected++;
            // break out of the while loop:
            break;
          }
          else 
          {      // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        }
        else if (c != '\r') 
        {    // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /%22/H/%22"))
        {
          digitalWrite(led, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /%22/L/%22")) 
        {
          digitalWrite(led, LOW);                // GET /L turns the LED off
        }
        if (currentLine.endsWith("GET /%22/1-1-1-1/%22")) 
        {
//          Serial.println("drink 1"); 
          digitalWrite(led, HIGH);  // Debugging 
          // TODO: pour drink 1 into cup 
        }
        else if (currentLine.endsWith("GET /%22/1-2-3-4/%22")) 
        {
//          Serial.println("drink 2"); 
          // TODO: pour drink 2 into cup 
        }
        else if (currentLine.endsWith("GET /%22/3-3-4-4%22/")) 
        {
//          Serial.println("drink 3"); 
         // TODO: pour drink 3 into cup 
        }
        else if (currentLine.endsWith("GET /%22/2-2-3-4/%22"))
        {
//          Serial.println("drink 4"); 
          // TODO: pour drink 4 into cup 
        }
        
      }
    }
//    // close the connection:
//    client.stop();
//    Serial.println("client disconnected");
  }
}

void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);

}
