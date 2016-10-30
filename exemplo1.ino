#include <sensors.h>

#define timer_scan 500

sensors sensor1(11,500, 3, 5000);
sensors sensor2(12,1000, 5, 3000);

void setup() {
   pinMode(8,OUTPUT);
   pinMode(9,OUTPUT);
   Serial.begin(9600);
}

void loop() {
  sensor1.scan_sensor();
  sensor2.scan_sensor();

  
  if(sensor1.sensor_is_alarmed() == true) {
    digitalWrite(8, HIGH);
  }else{
    digitalWrite(8, LOW);
  }

   if(sensor2.sensor_is_alarmed() == true) {
    digitalWrite(9, HIGH);
  }else{
    digitalWrite(9, LOW);
  }

}
