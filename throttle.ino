// Program used to test the USB Joystick object on the 
// Arduino Leonardo or Arduino Micro.
//
// Matthew Heironimus
// 2015-03-28 - Original Version
// 2015-11-18 - Updated to use the new Joystick library 
//              written for Arduino IDE Version 1.6.6 and
//              above.
// 2016-05-13   Updated to use new dynamic Joystick library
//              that can be customized.
//------------------------------------------------------------

#include "Joystick.h"

#define MIXTURE A0
#define TRIM_PITCH A3
#define THROTTLE A2
#define PROPELLER A1

// Create Joystick
// Joystick_ Joystick;
Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID,     // Report ID           (JOYSTICK_DEFAULT_REPORT_ID)
  JOYSTICK_TYPE_JOYSTICK,         // Joystick type       (JOYSTICK_TYPE_JOYSTICK)
  
  0,                              // button count        (JOYSTICK_DEFAULT_BUTTON_COUNT)
  0,                              // hat switch count    (JOYSTICK_DEFAULT_HATSWITCH_COUNT)

  false,                          // include X-Axis      (false)
  false,                          // include Y-Axis      (false)
  true,                           // include Z-Axis      (false)     MIXTURE

  true,                           // include Rx-Axis     (false)     PROPELLER
  true,                           // include Ry-Axis     (false)     TRIM_PITCH
  false,                          // include Rz+Axis     (false)
  
  false,                          // include rudder      (false)
  true,                           // include throttle    (false)     THROTTLE
  
  false,                          // include accelerator (false)
  false,                          // include brake       (false)
  false                           // include steering    (false)
);


void setup() {

  // Set Range Values
  Joystick.setRyAxisRange(0, 1024);       // TRIM_PITCH
  Joystick.setZAxisRange(0, 1024);        // MIXTURE
  Joystick.setThrottleRange(0, 1024);     // THROTTLE
  Joystick.setRxAxisRange(0, 1024);       // PROPELLER
    
  
  Joystick.begin(false);

  Joystick.setRyAxis(512); // TRIM_PITCH
  Joystick.setZAxis(0);    // MIXTURE
  Joystick.setThrottle(0); // THROTTLE
  Joystick.setRxAxis(0);   // PROPELLER

  Joystick.sendState();
}

void loop() {
 
  Joystick.setRyAxis(analogRead(TRIM_PITCH));         // TRIM_PITCH
  Joystick.setZAxis(1024 - analogRead(MIXTURE));      // MIXTURE
  Joystick.setThrottle(1024 - analogRead(THROTTLE));  // THROTTLE
  Joystick.setRxAxis(1024 - analogRead(PROPELLER));   // PROPELLER
  

  Joystick.sendState();

  delay(1);

}
