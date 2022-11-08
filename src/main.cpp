#include <Arduino.h>
#include <Servo.h>
#include "SimpleKalmanFilter.h"
#include "Pixetto.h"

#define sevo1_pin 2
#define servo1_angle_min 0
#define servo1_angle_max 180
#define servo1_angle_init 90

#define sevo2_pin 3
#define servo2_angle_min 0
#define servo2_angle_max 180
#define servo2_angle_init 90

#define sevo3_pin 6
#define servo3_angle_min 0
#define servo3_angle_max 180
#define servo3_angle_init 90

#define sevo4_pin 3
#define servo4_angle_min 0
#define servo4_angle_max 180
#define servo4_angle_init 90

#define rxPin 15
#define txPin 14

Pixetto ss(rxPin, txPin);

Servo pwmServo1; // (0deg, 90deg, 180deg)
Servo pwmServo2; // (0deg, 90deg, 180deg)
Servo pwmServo3; // (0deg, 90deg, 180deg)
Servo pwmServo4; // (0deg, 90deg, 180deg)

SimpleKalmanFilter KalmanFilter_X(1, 1, 0.01);
SimpleKalmanFilter KalmanFilter_Y(1, 1, 0.01);

int servo1Pos, servo2Pos, servo3Pos; // 當前角度
int KalmanX, KalmanY;

void setup() {

  //pinMode(9,INPUT_PULLUP); //ws2812上拉
  pwmServo1.attach(sevo1_pin);
  delay(10);
  pwmServo2.attach(sevo2_pin);
  delay(10);
  pwmServo3.attach(sevo3_pin);
  delay(10);

  ss.begin();
  ss.enableFunc(Pixetto::FUNC_COLOR_DETECTION);
  delay(10);
  Serial.begin(9600);
  
  servo1Pos = servo1_angle_init;
  servo2Pos = servo2_angle_init;
  servo3Pos = servo3_angle_init;

  pwmServo1.write(servo1Pos);
  pwmServo2.write(servo2Pos);
  pwmServo3.write(servo3Pos);
}

void loop() {
  if (ss.isDetected()) {
    Serial.print("x:");
    Serial.println(ss.getPosX());
    Serial.print("y:");
    Serial.println(ss.getPosY());
    Serial.print("w:");
    Serial.println(ss.getWidth());
    Serial.println("");
    KalmanX = KalmanFilter_X.updateEstimate(ss.getPosX());
    KalmanY = KalmanFilter_Y.updateEstimate(ss.getPosY());
    if (ss.getFuncID() == Pixetto::FUNC_COLOR_DETECTION) {
      if (ss.getTypeID() == Pixetto::COLOR_RED) {
        if (KalmanX >= 50) {
          servo1Pos -= 5;
          if (servo1Pos >= servo1_angle_max)
            servo1Pos = 180;
          pwmServo1.write(servo1Pos);
        }
        else if (KalmanX <= 25) {
          servo1Pos += 5;
          if (servo1Pos <= servo1_angle_min)
            servo1Pos = 0;
          pwmServo1.write(servo1Pos);
        }
        else if (KalmanY <= 17) {
          servo2Pos += 5;
          if (servo2Pos >= servo2_angle_max-20)
            servo2Pos = 160;
          pwmServo2.write(servo2Pos);

        }
        else if (KalmanY >= 60) {
          servo2Pos -= 5;
          if (servo2Pos <= servo2_angle_min)
            servo2Pos = 0;
          pwmServo2.write(servo2Pos);
        }

        if (servo2Pos <= 65) {
          servo3Pos = servo2Pos + 25;
          if (servo3Pos <= servo3_angle_min)
            servo3Pos = 0;
          pwmServo3.write(servo3Pos);
        }
        else if (servo2Pos >= 85) {
          servo3Pos = servo2Pos + 10;
          if (servo3Pos >= servo3_angle_max)
            servo3Pos = 180;
          pwmServo3.write(servo3Pos);
        }
        else {
          servo3Pos = servo3_angle_init;
          pwmServo3.write(servo3Pos);
        }

      }
    }
  }
}