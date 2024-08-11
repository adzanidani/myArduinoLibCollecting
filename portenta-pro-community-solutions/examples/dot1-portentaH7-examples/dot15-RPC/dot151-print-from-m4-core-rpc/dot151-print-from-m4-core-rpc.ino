
/*
 * e-print-from-m4-core-rpc.ino for the Portenta H7
 *
 * GNU GENERAL PUBLIC LICENSE
 * Use at your own risk.
 ************************************************ Important stuff if needed ****************************************
 *
 *
 *
 ********************************************************** end ****************************************************
 *
 *
 * The PortentaH7 M4 core can not print to the serial monitor
 * On the M4 core if you do a Serial.Println it goes to the TX RX UART output pins
 * This program uses RPC to redirect Serial.println to the M7 core 
 * so that regular sketches still work with serial monitor output from the M4 core
 *
 * 
 * updated August 2nd, 2020
 * by Jeremy Ellis
 * Twitter @rocksetta
 * Website https://www.rocksetta.com
 *
 * I have re-written this to make larger programs easier
 * by seperating the M7 and M4 code completely.
 *
*/



#ifdef CORE_CM7   // Start M7 programming
 
#include "RPC.h"  // comes with the mbed board installation

void setup() {
   bootM4(); 
   Serial.begin(115200);
   RPC.begin();
}

void loop() {
  
   while (RPC.available()) {
      Serial.write(RPC.read()); 
   }  
  // delay(1);
}

#endif              // End all M7 core programming




/////////////////////////////////////////////////////////////////////////////////////////////

#ifdef CORE_CM4    // Start M4 programming

#include "RPC.h"  // comes with the mbed board installation

#define Serial RPC  // So the M4 regular serial prints to RPC

void setup(){  
  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin();
  // while (!Serial);  // Please don't do this it messes up beginners
  
}

void loop() {

  Serial.println( ); delayMicroseconds(1234);
  Serial.println("A0 Analog Read max = 1023, Actual Value: "+String(analogRead(A0)) ); delayMicroseconds(1234);
  Serial.println("A1 Analog Read max = 1023, Actual Value: "+String(analogRead(A1)) ); delayMicroseconds(1234);
  Serial.println("A2 Analog Read max = 1023, Actual Value: "+String(analogRead(A2)) ); delayMicroseconds(1234);
  Serial.println("A3 Analog Read max = 1023, Actual Value: "+String(analogRead(A3)) ); delayMicroseconds(1234);
  Serial.println("A4 Analog Read max = 1023, Actual Value: "+String(analogRead(A4)) ); delayMicroseconds(1234);
  Serial.println("A5 Analog Read max = 1023, Actual Value: "+String(analogRead(A5)) ); delayMicroseconds(1234);
  Serial.println("A6 Analog Read max = 1023, Actual Value: "+String(analogRead(A6)) ); delayMicroseconds(1234);
  Serial.println("-----------------------------------------------------------------"); delayMicroseconds(1234);
  Serial.println(); delayMicroseconds(1234);

  // Flash LED 3 times
  digitalWrite(LED_BUILTIN, LOW);   
  delay(10);                      
  digitalWrite(LED_BUILTIN, HIGH);    
  delay(10);                    

  digitalWrite(LED_BUILTIN, LOW);   
  delay(10);                      
  digitalWrite(LED_BUILTIN, HIGH);    
  delay(10);      
                
  digitalWrite(LED_BUILTIN, LOW);   
  delay(10);                      
  digitalWrite(LED_BUILTIN, HIGH);    
  delay(100);    // longer wait 
                  
}
  


#endif            // End all M4 core programming










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

