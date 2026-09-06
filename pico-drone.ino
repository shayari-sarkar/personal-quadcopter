
// #include <Servo.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#define MPU_ADDR 0x68
Servo TL, BL, TR, BR;  
int angleForward, angleReverse;
Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    delay(10);

  TL.attach(0);  // Attach the servo to GPIO pin 0
  BL.attach(13);  // Attach the servo to GPIO pin 13
  TR.attach(28);  // Attach the servo to GPIO pin 28
  BR.attach(17);  // Attach the servo to GPIO pin 17
  
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);           // PWR_MGMT_1 register
  Wire.write(0x00);           // Wake up MPU6050 (set sleep = 0)
  Wire.endTransmission(true);

  if (mpu.begin())
  {
    Serial.println("MPU FOUND!!!");
  }
  else
  {
    Serial.println("not working");

  }

}

void loop() {
  Serial.println("Test");
    // TL and BR (CW)
  // TR and BL (CCW)

  for (int angle = 0; angle <= 180; angle += 10) {
    angleForward = angle;
    angleReverse = 180 - angle;
    
    TL.write(angleForward);
    BR.write(angleForward);

    TR.write(angleReverse);
    BL.write(angleReverse);
    delay(30);
  }

  for (int angle = 180; angle >= 0; angle -= 10) {
    angleForward = angle;
    angleReverse = 180 - angle;

    TL.write(angleForward);
    BR.write(angleForward);

    TR.write(angleReverse);
    BL.write(angleReverse);
    delay(30);
  }
  
}
