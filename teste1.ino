#include <diego.h>

#define timer_scan 500

diego sensor1(11,timer_scan, 5, 10000);

void setup() {
   pinMode(12,OUTPUT);
   pinMode(13,OUTPUT);
   Serial.begin(9600);
}

void loop() {
  sensor1.scan_sensor();

  
  if(sensor1.sensor_is_alarmed() == true) {
    digitalWrite(12, HIGH);
  }else{
    digitalWrite(12, LOW);
  }
}
