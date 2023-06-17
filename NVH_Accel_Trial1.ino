// Basic demo for accelerometer readings from Adafruit MPU6050

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
//#include <SoftwareSerial.h>
Adafruit_MPU6050 mpu;

unsigned long long Ctime;

void setup(void) {
  Serial.begin(56000);   //56000
   Wire.begin(D2, D1);  //SDA SCL
  Serial.println("CLEARDATA");
  Serial.println("LABEL, Time,MillisTime, X,Y,Z,gx,gy,gz");
  Serial.println("RESETTIMER");
  
 
 // Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
        Serial.println("Failed to find MPU6050 chip");

    while (1) {
      delay(10);
    }
  }
  //Serial.println("MPU6050 Found!");
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  // set gyro range to +- 500 deg/s
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  // set filter bandwidth to 21 Hz
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
 


}

void loop() {

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);


Serial.print("DATA, TIME,");
  /* Print out the values */
//  Serial.print("Acceleration X: ");
  Serial.print(millis());
  Serial.print(" ,");
  Serial.print(a.acceleration.x);
  Serial.print(" ,");
  //Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(" ,");
  //Serial.print(", Z:      ");
  Serial.print(a.acceleration.z);
  Serial.print(" ,");
    
  Serial.print(g.gyro.x);
  Serial.print(" ,");
  Serial.print(g.gyro.y);
  Serial.print(" ,");
  Serial.print(g.gyro.z);
  Serial.print(" ,");

 Serial.print('\n');
 
  delay(5);
}
