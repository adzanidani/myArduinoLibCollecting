/* 
*  .ino for the Portenta H7
*
* GNU GENERAL PUBLIC LICENSE
* Use at your own risk.
************************************************ Important stuff if needed ****************************************
*
* Must connect the short wire of an LED to a small ohm resistor
* connect the resistor to ground (GND)
* and the long wire of the LED to a digital output D5
* 
* Connect a button to both D6 and the other end to 3V3
********************************************************** end ****************************************************
*
*  July 22nd, 2020
*  by Jeremy Ellis
*  Twitter @rocksetta
*  Website https://www.rocksetta.com
*/

#include <Arduino.h> // Only needed by https://platformio.org/

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // LEDB = blue, LEDG or LED_BUILTIN = green, LEDR = red 
  pinMode(D5, OUTPUT);              // external LED also connected to a resisator and GND
  pinMode(D6, INPUT_PULLDOWN);      // Connect a button or switch from D6to the button to 3V3
}

void loop() {
  if (digitalRead(D6)){
      digitalWrite(LED_BUILTIN, LOW);   // Internal LED on, weird right
      digitalWrite(D5, HIGH);           // External LED on
  } else {
      digitalWrite(LED_BUILTIN, HIGH);   // Internal LED off
      digitalWrite(D5, LOW);           // External LED off  
  }  
  // no delay needed since button/switch controls the action
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
