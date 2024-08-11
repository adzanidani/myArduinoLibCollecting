/*
*
* GNU GENERAL PUBLIC LICENSE
* Use at your own risk.
************************************************ Important stuff if needed ****************************************
*
* The following code will give you a local IP address to use. 
* Use the serial monitor to find your local IP. Then should work with or without serial monitor.
*
* Up to your router to assign outside Ethernet Access. This part can be complex.
* Make sure the etherenet cable is plugged into either the Breakout board or Vision Shield.
*
********************************************************** end ****************************************************
*
*/

#include <Arduino.h> // Only needed by https://platformio.org/
#include <Portenta_Ethernet.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 177);  // what are these for??

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);



void setup() {

  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);      // set the LED Green pin mode  
  pinMode(LEDB, OUTPUT);             
  digitalWrite(LEDB, HIGH);  
  digitalWrite(LED_BUILTIN, LOW);  
  
  delay(5000);  // time to get serial monitor working if needed
  Serial.println("Wait a few seconds to plug in serial");
  delay(5000);  
  Serial.println(".");
  delay(5000);   
  Serial.println(".");

  
  Serial.println("Ethernet WebServer Example");

  // start the Ethernet connection and the server:
  Ethernet.begin(mac);

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

  // start the server
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
  digitalWrite(LEDB, LOW);  
  digitalWrite(LED_BUILTIN, HIGH); 
}


void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
   if (client) {                             // if you get a client,
    
    Serial.print("server is at ");
    Serial.println(Ethernet.localIP());
  
    Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
           //client.println("{answer:42}");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("<input type=button value='LED BLUE Off' onclick='{location=\"/H\"}'>");
            client.print("<input type=button value='LED BLUE On' onclick='{location=\"/L\"}'>");

            // The HTTP response ends with another blank line:
            client.println();    
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(LEDB, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(LEDB, LOW);                // GET /L turns the LED off
        }
      }
    }
    // close the connection:
    client.stop();

  }
}





/*
* Clickable links for helpful information
* By @rocksetta
* March, 2021
* GNU GENERAL PUBLIC LICENSE
* Use at your own risk.
*
*
*
*  Artduino Pro Links:
*
*  https://store.arduino.cc/usa/portenta-h7
*  https://forum.arduino.cc/index.php?board=148.0
*  https://www.arduino.cc/pro/tutorials/portenta-h7
*
*  Rocksetta links:
* 
*  https://twitter.com/rocksetta
*  https://github.com/hpssjellis/portenta-pro-community-solutions
*  https://github.com/hpssjellis/my-examples-for-the-arduino-portentaH7
*  https://github.com/hpssjellis/arduino-high-school-robotics-course
*  https://www.youtube.com/playlist?list=PL57Dnr1H_egtm0pi-okmG0iE_X5dROaLw
*
*
*
*/

