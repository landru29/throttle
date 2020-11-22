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

// Create Joystick
// Joystick_ Joystick;
Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID,     // Report ID           (JOYSTICK_DEFAULT_REPORT_ID)
  JOYSTICK_TYPE_JOYSTICK,       // Joystick type       (JOYSTICK_TYPE_JOYSTICK)
  
  0,                             // button count        (JOYSTICK_DEFAULT_BUTTON_COUNT)
  0,                              // hat switch count    (JOYSTICK_DEFAULT_HATSWITCH_COUNT)

  true,                           // include X-Axis      (true)
  true,                           // include Y-Axis      (true)
  true,                          // include Z-Axis      (true)

  false,                          // include Rx-Axis     (true)
  false,                          // include Ry-Axis     (true)
  false,                          // include Rz+Axis     (true)
  
  false,                           // include rudder      (true)
  false,                           // include throttle    (true)
  
  false,                          // include accelerator (true)
  false,                          // include brake       (true)
  false                           // include steering    (true)
);


void setup() {

  // Set Range Values
  Joystick.setXAxisRange(0, 1024);
  Joystick.setYAxisRange(0, 1024);
  Joystick.setZAxisRange(0, 1024);

  // Joystick.setRxAxisRange(0, 360);
  // Joystick.setRyAxisRange(360, 0);
  // Joystick.setRzAxisRange(0, 720);

  // Joystick.setRudderRange(0, 1024);
  // Joystick.setThrottleRange(0, 1024);
  // Joystick.setAcceleratorRange(0, 1024);
  
  // Joystick.setBrakeRange(-127, 127);
  // Joystick.setSteeringRange(-127, 127);
    
  
  Joystick.begin(false);

  Joystick.setXAxis(0);
  Joystick.setYAxis(0);
  Joystick.setZAxis(0);

  // Joystick.setRxAxis(180);
  // Joystick.setRyAxis(180);
  // Joystick.setRzAxis(360);

  // Joystick.setRudder(512);
  // Joystick.setThrottle(512);
  // Joystick.setAccelerator(512);
  
  // Joystick.setBrake(0);
  // Joystick.setSteering(0);

  Joystick.sendState();
}

void loop() {

  Joystick.setXAxis(analogRead(A0));
  Joystick.setYAxis(analogRead(A1));
  Joystick.setZAxis(analogRead(A2));
  

  Joystick.sendState();

  delay(1);

}
