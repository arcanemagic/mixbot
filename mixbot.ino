#include <SPI.h>
#include <WiFiNINA.h>
#include <iostream> 
#include <fstream> 
#include <sstream>
#include <regex>
#include "homepagehtml.h"

using namespace std;  

// Motor A connections 
int enA = 9;
int in2 = 8;
int in1 = 7;
// Motor B connections
int enB = 3;
int in4 = 5;
int in3 = 4;
// Motor C connections
int enC = 16;
int in6 = 15;
int in5 = 14;
// Motor D connections
int enD = 19;
int in7 = 20;
int in8 = 21;

char ssid[] = "cocktail";        // your network SSID (name)
char pass[] = "12345678";        // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;                // your network key index number (needed only for WEP)

int led =  LED_BUILTIN;
int status = WL_IDLE_STATUS;
WiFiServer server(80);

float time_connected = 0; 

struct DrinkOrder{
 int amounts[4]; 
};

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


    // Set all the motor control pins to outputs
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(enC, OUTPUT);
    pinMode(enD, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(in5, OUTPUT);
    pinMode(in6, OUTPUT);
    pinMode(in7, OUTPUT);
    pinMode(in8, OUTPUT);
    
    // Turn off motors - Initial state
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6, LOW);
    digitalWrite(in7, LOW);
    digitalWrite(in8, LOW);
}

int pourDrinks(DrinkOrder order)
{
  // TODO: turn on the motors for the appropriate durations 
  // Each entry in order.amounts[i] represents the amount to pour 

  // Turn on the LED to indicate we're working on a drink 
  digitalWrite(led, HIGH); 

  Serial.println("in pourDrinks()"); 
  Serial.println("Preparing to pour: "); 
  int max = order.amounts[0]; 
  for(int i = 0; i < 4; i++) // Print the amounts to serial monitor (for debugging) 
  {
    Serial.print("Drink "); 
    Serial.print(i); 
    Serial.print(": "); 
    Serial.println(order.amounts[i]); 
    if(order.amounts[i] > max)
      max = order.amounts[i]; 
  }
  Serial.print("Max is ");
  Serial.println(max); 

  analogWrite(enA, 255);
  analogWrite(enB, 255);
  analogWrite(enC, 255);
  analogWrite(enD, 255);

//  digitalWrite(in1, HIGH);
//  digitalWrite(in3, HIGH);
//  digitalWrite(in5, HIGH);
//  digitalWrite(in7, HIGH);

  int motor1_time = 0; 
  int motor2_time = 0; 
  int motor3_time = 0; 
  int motor4_time = 0; 
  for(int i = 0; i < 4* max; i++) // Turn on motors for the appropriate durations 
  {
    if(motor1_time < 4*order.amounts[0])
    {
      digitalWrite(in1, HIGH);// turn on 
      motor1_time++; 
    }
    else
    {
      digitalWrite(in1, LOW); //turn off 
    }
    
    if(motor2_time < 4*order.amounts[1])
    {
      digitalWrite(in3, HIGH);
      motor2_time++;
    }
    else
    {
      digitalWrite(in3, LOW); // turn off 
    }
    
    if(motor3_time < 4*order.amounts[2])
    {
      digitalWrite(in5, HIGH);
      motor3_time++; 
    }
    else
    {
      digitalWrite(in5, LOW); // turn off 
    }
    
    if(motor4_time < 4*order.amounts[3])
    {
      digitalWrite(in7, HIGH);
      motor4_time++; 
    }
    else
    {
      digitalWrite(in7, LOW); // turn off 
    }

    Serial.println("Pouring drinks for one second"); 
    delay(1000); 
  }

//  delay(5000);

  digitalWrite(in1, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in7, LOW);
  
  // Turn off the delay to indicate the drink is done 
  // delay(1000); // Delay for debugging purposes, remove later 
  digitalWrite(led, LOW); 

  
  return 0; 
}

DrinkOrder parseGetRequest(std::string url)
{
  DrinkOrder order; 
  std::string delimiter = "&"; 
  std::string s = url; 
  std::string token = ""; 
  unsigned int position = 0;
  Serial.println("Parsing: ");
  Serial.println(url.c_str()); 
  int index = 0; 
  while ((position = s.find(delimiter)) != std::string::npos) 
  {
    token = s.substr(0, position);
//    Serial.println(token.c_str());

    int amountpos = 0; 
    if( (amountpos = token.find("=")) != std::string::npos)
    {
      int amount = std::stoi(token.substr( token.find("=") + 1, 1)); 
//      Serial.println(amount); 
      order.amounts[index] = amount; 
      index++; 
    }
    s.erase(0, position + delimiter.length());
  }
  
  // Get the last drink (drink 4): 
//  Serial.println(s.c_str()); 
  int amount = std::stoi(s.substr( s.find("=") + 1, 1)); 
//  Serial.println(amount); 
  order.amounts[index] = amount; 

  Serial.println("parseGetRequest() parsed drink amounts as: "); 
  for(int i = 0; i < 4; i++)
    Serial.println(order.amounts[i]); 

//  Serial.println("Finished parsing get request"); 

  pourDrinks(order); 
  return order; 
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

            // the content of the HTTP response (the webpage) follows the header:
             client.print(indexhtml.c_str()); 

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

        std::string stdCurrentLine(currentLine.c_str()); 
//        std::regex regex_expr("(GET /\\?drink1)=[0-9]&drink2=[0-9]&drink3=[0-9]&drink4=[0-9] HTTP/1.1\r");
        // Not as exact as using regex matching, 
        // but regex matching causes noticeable lag, 
        // since the while loop is for *every character* 
        // Note that this breaks if any of the drink amounts are two digits (e.g. 10) or if you change labels in the html (drink1, drink2, etc.)
        if(currentLine.startsWith("GET /?") && currentLine.length() == 41) 
        {
          Serial.println("\nRECEIVED AN ORDER"); 
          parseGetRequest(stdCurrentLine); 
        }

        
        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H"))
        {
          digitalWrite(led, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /L")) 
        {
          digitalWrite(led, LOW);                // GET /L turns the LED off
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
