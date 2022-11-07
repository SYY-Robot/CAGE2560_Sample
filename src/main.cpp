#include <Arduino.h>
#include <PS2X_lib.h>  //for v1.6
#include <SparkFun_TB6612.h>

/******************************************************************
 * set pins connected to PS2 controller:
 *   - 1e column: original
 *   - 2e colmun: Stef?
 * replace pin numbers by the ones you use
 ******************************************************************/
#define PS2_DAT        7  //14    
#define PS2_CMD        6  //15
#define PS2_SEL        2  //16
#define PS2_CLK        3  //17

/******************************************************************
   * select modes of PS2 controller:
   *   - pressures = analog reading of push-butttons
   *   - rumble    = motor rumbling
   * uncomment 1 of the lines for each mode selection
   ******************************************************************/
   //#define pressures   true
#define pressures   false
//#define rumble      true
#define rumble      false

PS2X ps2x; // create PS2 Controller Class

//right now, the library does NOT support hot pluggable controllers, meaning 
//you must always either restart your Arduino after you connect the controller, 
//or call config_gamepad(pins) again after connecting the controller.

Motor motor0 = Motor(37, 38, 12, 1, -1);
Motor motor1 = Motor(39, 40, 13, 1, -1);
Motor motor2 = Motor(33, 34, 5, 1, -1);
Motor motor3 = Motor(35, 36, 11, 1, -1);

int error = 0;
byte type = 0;
byte vibrate = 0;

void setup() {

   Serial.begin(9600);

   unsigned long start = millis();

   //CHANGES for v1.6 HERE!!! **************PAY ATTENTION*************
   while (millis()-start>500)
   {
      ;
   }
   

   //setup pins and settings: GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
   error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);

   if (error == 0) {
      Serial.print("Teleop start");
   }
}

void loop() {
   
   if(ps2x.read_gamepad(false,vibrate)){
      Serial.println("read_gamepad successed");
      delay(100);
   }
   else{
      printf("read_gamepad failed\r\n");
      return;
   }
   unsigned long get_command = 0;
   if (ps2x.Button(PSB_PAD_UP)) {      //will be TRUE as long as button is pressed
      //Serial.print("Up held this hard: ");
      //Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);
      motor0.drive(100);
      motor1.drive(100);
      motor2.drive(-100);
      motor3.drive(-100);
      get_command = millis();
   }
   if (ps2x.Button(PSB_PAD_RIGHT)) {
      //Serial.print("Right held this hard: ");
      //Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
      motor0.drive(100);
      motor1.drive(-100);
      motor2.drive(-100);
      motor3.drive(100);
      get_command = millis();
   }
   if (ps2x.Button(PSB_PAD_LEFT)) {
      //Serial.print("LEFT held this hard: ");
      //Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
      motor0.drive(-100);
      motor1.drive(100);
      motor2.drive(100);
      motor3.drive(-100);
      get_command = millis();
   }
   if (ps2x.Button(PSB_PAD_DOWN)) {
      //Serial.print("DOWN held this hard: ");
      //Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);
      motor0.drive(-100);
      motor1.drive(-100);
      motor2.drive(100);
      motor3.drive(100);
      get_command = millis();
   }
   if(ps2x.Button(PSB_R1)){
      motor0.drive(100);
      motor1.drive(0);
      motor2.drive(-100);
      motor3.drive(0);
      get_command = millis();
   }
   if(ps2x.Button(PSB_L1)){
      motor0.drive(0);
      motor1.drive(100);
      motor2.drive(0);
      motor3.drive(-100);
      get_command = millis();
   }
   if(ps2x.Button(PSB_R2)){
      motor0.drive(0);
      motor1.drive(-100);
      motor2.drive(0);
      motor3.drive(100);
      get_command = millis();
   }
   if(ps2x.Button(PSB_L2)){
      motor0.drive(-100);
      motor1.drive(0);
      motor2.drive(100);
      motor3.drive(0);
      get_command = millis();
   }
   if(ps2x.ButtonPressed(PSB_SQUARE)){
      motor0.drive(-100);
      motor1.drive(-100);
      motor2.drive(-100);
      motor3.drive(-100);
      get_command = millis();
   }
   if(ps2x.ButtonPressed(PSB_CIRCLE)){
      motor0.drive(100);
      motor1.drive(100);
      motor2.drive(100);
      motor3.drive(100);
      get_command = millis();
   }

   if(millis()-get_command > 250){
      motor0.drive(0);
      motor1.drive(0);
      motor2.drive(0);
      motor3.drive(0);
   }
}
