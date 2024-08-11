/*  For any gotchas that might not be obvious to a new user
*
*
*
*  Note: The Wifi updator also updates the CERT used for Ethernet SSL!   May 2022  Arduino MBED Core Version 3.01
*
*
*
*
*
*  A3 digital output does not work if A5 or D8 is also connected for digital output. 
*  The above will be a pain for SPI connections using MOSI (COPI) D8
*
*  A2 digital output does not work if A4 or D10 is also connected for digital output 
*  The above will be a pain for SPI connections using MISO (CIPO) D8
* see isue   https://github.com/arduino/ArduinoCore-mbed/issues/488
*
*
*
*
*
*
*
*  Example: A0, A1, A2, A3 not to be used for general GPIO 
*  All Analog pins are not to be used for PWM
*
*
*
*
*
*
*
*

Not a problem with Arduino but if using edgeimpulse then be aware of these re-defines in the main cpp program loaded

SHould mean pin numbers 0, 1, 2 are fine but A0, A1, A2 are not fine to use.


// Undefine min/max macros as these conflict with C++ std min/max functions
// these are often included by Arduino cores
#include <Arduino.h>
#include <stdarg.h>
#ifdef min
#undef min
#endif // min
#ifdef max
#undef max
#endif // max
#ifdef round
#undef round
#endif // round
// Similar the ESP32 seems to define this, which is also used as an enum value in TFLite
#ifdef DEFAULT
#undef DEFAULT
#endif // DEFAULT
// Infineon core defines this, conflicts with CMSIS/DSP/Include/dsp/controller_functions.h
#ifdef A0
#undef A0
#endif // A0
#ifdef A1
#undef A1
#endif // A1
#ifdef A2
#undef A2
#endif // A2


*
*
*
*
*
*
*
*
*
*
*
*/


