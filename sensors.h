/*
Author: Diego Narducci Arioza
Contato: diego.ariozza@gmail.com
*/

#ifndef sensors_h
#define sensors_h

#include "Arduino.h"

class sensors {
	public:
    	sensors(int pin, int scan_interval, int count_scan, int time_alarmed, String local_sensor, bool trigger_up_or_down = false);
		static void var_global();

		void scan();
		void start();
		void stop();
		void print(int print_interval);
		void loop();
	    bool is_alarmed();
		bool _trigger_up_or_down;

		//
		bool loop_v = false;
		unsigned long _loop_millis = 0;
		
		String local;
	   
    private:
		// --- construtor
        int _pin;
		int _scan_interval;
		int _count_scan;
		int _time_alarmed;
		// --- scan
		unsigned long _tempo_millis = 0;
	    unsigned long _tempo_millis_alarmed = 0;
	    unsigned long _tempo_millis_zero = 0;		
	    int _count_scan_inc;
		bool sensor_run;
		bool _alarmed;
		// --- print
		unsigned long _print_interval_millis = 0;
};

class ldr {
	public:
		ldr(int pin);
		void scan_sensor();

	private:
};
#endif


