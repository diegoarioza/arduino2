#include <sensors.h>

#define sirene 12

sensors sensor1(8,500, 3, 5000, "sala", false);
sensors sensor2(9,500, 3, 5000, "sala", false);

void setup() {
  sensor1.start();
  sensor2.start();
}

void loop() {
  sensor1.scan();
  sensor2.scan();
  
  if(sensor1.is_alarmed() || sensor2.is_alarmed()) {
    digitalWrite(sirene, HIGH);
  }else{
    digitalWrite(sirene, LOW);
  }

  sensor1.print(1000);
  sensor1.loop();
}
