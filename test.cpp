#include <Arduino.h>
//#include <SparkFun_TB6612.h>
//#include <RotaryEncoder.h>
#include <PS2X_lib.h>

#define PS2_DAT        7  //14    
#define PS2_CMD        6  //15
#define PS2_SEL        2  //16
#define PS2_CLK        3  //17
//#define pressures   true
#define pressures   false
//#define rumble      true
#define rumble      false
int error = 0;

/*Motor motor0 = Motor(37, 38, 12, 1, -1);
Motor motor1 = Motor(39, 40, 13, 1, -1);
Motor motor2 = Motor(33, 34, 5, 1, -1);
Motor motor3 = Motor(35, 36, 11, 1, -1);*/
//RotaryEncoder enc0(A12, A13, RotaryEncoder::LatchMode::FOUR3), enc1(A14, A15, RotaryEncoder::LatchMode::FOUR3), enc2(A8, A9, RotaryEncoder::LatchMode::FOUR3), enc3(A10, A11, RotaryEncoder::LatchMode::FOUR3);
PS2X ps2x; // create PS2 Controller Class

/*#if defined(__AVR_ATmega2560__)
ISR(PCINT2_vect) {
   enc0.tick();
   enc1.tick();
   enc2.tick();
   enc3.tick();
}
#endif*/

void setup()
{
   Serial.begin(9600);
   error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
   if (error == 0) {
      Serial.print("Found Controller, configured successful ");
      Serial.print("pressures = ");
      if (pressures)
         Serial.println("true ");
      else
         Serial.println("false");
      Serial.print("rumble = ");
      if (rumble)
         Serial.println("true)");
      else
         Serial.println("false");
      Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
      Serial.println("holding L1 or R1 will print out the analog stick values.");
      Serial.println("Note: Go to www.billporter.info for updates and to report bugs.");
   }
   else if (error == 1)
      Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");

   else if (error == 2)
      Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");

   else if (error == 3)
      Serial.println("Controller refusing to enter Pressures mode, may not support it. ");

/*#if defined(__AVR_ATmega2560__)
   cli();
   PCMSK2 = 0xff;
   PCICR |= (1 << PCIE2);
   sei();
#endif*/

}


void loop()
{
   /*motor0.drive(100);
   motor1.drive(100);
   motor2.drive(100);
   motor3.drive(100);*/

   /*
   Serial.println(enc0.getPosition());
   Serial.println(enc1.getPosition());
   Serial.println(enc2.getPosition());
   Serial.println(enc3.getPosition());
   */
}