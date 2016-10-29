

#ifndef diego_h
#define diego_h


#include "Arduino.h"


class diego
{
   public:
       diego(int pin, int time_scan_sensor, int count, int time_alarmed);
       bool scan_sensor();
	   bool sensor_is_alarmed();
	   
   private:
	   bool _alarmed;
	   bool _is_alarmed;
       int _pin;
	   int _tempo;
	   int _count;
	   int _count_test;
	   int _time_alarmed;
	   int _time_scan_sensor;
	   unsigned long _tempo_millis;
	   unsigned long _tempo_millis_alarmed;
	   unsigned long _tempo_millis_zero;
};


#endif
