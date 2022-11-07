#include <Arduino.h>
#include <Servo.h>

// B2、D2方向相反
#define servo_A1 2
#define servo_A2 3
#define servo_B1 45
#define servo_B2 46
#define servo_C1 A3
#define servo_C2 A4
#define servo_D1 A5
#define servo_D2 A6

#define servo_init_angle 90
#define servo_max_angle 175
#define servo_min_angle 10

Servo spider_servo_1;
Servo spider_servo_2;
Servo spider_servo_3;
Servo spider_servo_4;
Servo spider_servo_5;
Servo spider_servo_6;
Servo spider_servo_7;
Servo spider_servo_8;

void servo_init();
void servo_sit();
void servo_stand();
void servo_move0();
void servo_back();
void servo_turnLeft();
void servo_turnRight();

char c;


void setup() {
   Serial.begin(9600);
   servo_init();
   unsigned long start = millis();
   while (millis() - start > 1000)
   {
      ;
   }
   //servo_stand();
}

void loop() {

   if(Serial.available() > 0){
      
      c = Serial.read();
      if(c == 'F'){
         //spider_servo_1.attach(0);
         servo_move0();
      }
      else if(c == 'G'){
         //spider_servo_1.attach(90);
         servo_back();
      }
      else if(c == 'R'){
         //spider_servo_1.attach(180);
         servo_turnRight();
      }
      else if(c == 'L'){
         //spider_servo_1.attach(0);
         servo_turnLeft();
      }
   }
}

void servo_init() {
   spider_servo_1.attach(servo_A1);
   spider_servo_2.attach(servo_A2);
   spider_servo_3.attach(servo_B1);
   spider_servo_4.attach(servo_B2);
   spider_servo_5.attach(servo_C1);
   spider_servo_6.attach(servo_C2);
   spider_servo_7.attach(servo_D1);
   spider_servo_8.attach(servo_D2);
}

void servo_sit() {
   spider_servo_1.write(servo_init_angle);
   spider_servo_2.write(servo_max_angle);
   spider_servo_3.write(servo_init_angle);
   spider_servo_4.write(servo_min_angle);
   spider_servo_5.write(servo_init_angle);
   spider_servo_6.write(servo_max_angle);
   spider_servo_7.write(servo_init_angle);
   spider_servo_8.write(servo_min_angle);
}

void servo_stand() {
   spider_servo_1.write(servo_init_angle);
   spider_servo_2.write(servo_init_angle);
   spider_servo_3.write(servo_init_angle);
   spider_servo_4.write(servo_init_angle);
   spider_servo_5.write(servo_init_angle);
   spider_servo_6.write(servo_init_angle);
   spider_servo_7.write(servo_init_angle);
   spider_servo_8.write(servo_init_angle);
}

void servo_move0(){
   spider_servo_2.write(servo_init_angle+60);//1組腳抬起
   spider_servo_6.write(servo_init_angle+60);
   delay(300);
   spider_servo_1.write(servo_init_angle-40);//1組腳往前走
   spider_servo_5.write(servo_init_angle+40);
   delay(300);
   spider_servo_2.write(servo_init_angle);//1組腳放下
   spider_servo_6.write(servo_init_angle);
   delay(300);
   spider_servo_1.write(servo_init_angle);//1組腳往後伸
   spider_servo_5.write(servo_init_angle);
   delay(300);
   spider_servo_4.write(servo_init_angle-60);//2組腳抬起
   spider_servo_8.write(servo_init_angle-60);
   delay(300);
   spider_servo_3.write(servo_init_angle+40);//2組腳往前走
   spider_servo_7.write(servo_init_angle-40);
   delay(300);
   spider_servo_4.write(servo_init_angle);//2組腳放下
   spider_servo_8.write(servo_init_angle);
   delay(300);
   spider_servo_3.write(servo_init_angle);//2組腳往後伸
   spider_servo_7.write(servo_init_angle);
   delay(100);
}

void servo_back(){
   spider_servo_2.write(servo_init_angle+60);//1組腳抬起
   spider_servo_6.write(servo_init_angle+60);
   delay(300);
   spider_servo_1.write(servo_init_angle+40);//1組腳往前走
   spider_servo_5.write(servo_init_angle-40);
   delay(300);
   spider_servo_2.write(servo_init_angle);//1組腳放下
   spider_servo_6.write(servo_init_angle);
   delay(300);
   spider_servo_1.write(servo_init_angle);//1組腳往後伸
   spider_servo_5.write(servo_init_angle);
   delay(300);
   spider_servo_4.write(servo_init_angle-60);//2組腳抬起
   spider_servo_8.write(servo_init_angle-60);
   delay(300);
   spider_servo_3.write(servo_init_angle-40);//2組腳往前走
   spider_servo_7.write(servo_init_angle+40);
   delay(300);
   spider_servo_4.write(servo_init_angle);//2組腳放下
   spider_servo_8.write(servo_init_angle);
   delay(300);
   spider_servo_3.write(servo_init_angle);//2組腳往後伸
   spider_servo_7.write(servo_init_angle);
   delay(100);
}

void servo_turnRight(){
   spider_servo_2.write(servo_init_angle+60);//1組腳抬起
   spider_servo_6.write(servo_init_angle+60);
   delay(300);
   spider_servo_1.write(servo_init_angle+40);//1組腳往前走
   spider_servo_5.write(servo_init_angle+40);
   delay(300);
   spider_servo_2.write(servo_init_angle);//1組腳放下
   spider_servo_6.write(servo_init_angle);
   delay(300);
   spider_servo_1.write(servo_init_angle);//1組腳往後伸
   spider_servo_5.write(servo_init_angle);
   delay(300);
   spider_servo_4.write(servo_init_angle-60);//2組腳抬起
   spider_servo_8.write(servo_init_angle-60);
   delay(300);
   spider_servo_3.write(servo_init_angle+40);//2組腳往前走
   spider_servo_7.write(servo_init_angle+40);
   delay(300);
   spider_servo_4.write(servo_init_angle);//2組腳放下
   spider_servo_8.write(servo_init_angle);
   delay(300);
   spider_servo_3.write(servo_init_angle);//2組腳往後伸
   spider_servo_7.write(servo_init_angle);
   delay(100);
}

void servo_turnLeft(){
   spider_servo_2.write(servo_init_angle+60);//1組腳抬起
   spider_servo_6.write(servo_init_angle+60);
   delay(300);
   spider_servo_1.write(servo_init_angle-40);//1組腳往前走
   spider_servo_5.write(servo_init_angle-40);
   delay(300);
   spider_servo_2.write(servo_init_angle);//1組腳放下
   spider_servo_6.write(servo_init_angle);
   delay(300);
   spider_servo_1.write(servo_init_angle);//1組腳往後伸
   spider_servo_5.write(servo_init_angle);
   delay(300);
   spider_servo_4.write(servo_init_angle-60);//2組腳抬起
   spider_servo_8.write(servo_init_angle-60);
   delay(300);
   spider_servo_3.write(servo_init_angle-40);//2組腳往前走
   spider_servo_7.write(servo_init_angle-40);
   delay(300);
   spider_servo_4.write(servo_init_angle);//2組腳放下
   spider_servo_8.write(servo_init_angle);
   delay(300);
   spider_servo_3.write(servo_init_angle);//2組腳往後伸
   spider_servo_7.write(servo_init_angle);
   delay(100);
}