/*
Author: Diego Narducci Arioza
Contato: diego.ariozza@gmail.com
*/

#include "Arduino.h"
#include "sensors.h"

static String var_glob_string1;
static int var_glob_int1;
static bool var_glob_bool1;

// INICIO DA CLASSE SENSORS
sensors::sensors(int pin, int scan_interval, int count_scan, int time_alarmed, String local_sensor, bool trigger_up_or_down = false) {
	pinMode(pin, INPUT);
	_pin = pin;
	_scan_interval = scan_interval;
	_count_scan = count_scan;
	_time_alarmed = time_alarmed;
	local = local_sensor;
	_trigger_up_or_down = trigger_up_or_down;
	// ----
	_tempo_millis = 0;
	_tempo_millis_alarmed = 0;
	_tempo_millis_zero = 0;
	_alarmed = false;

	sensor_run = false;
}

void sensors::scan() {      												
	if(sensor_run == true) {                                               				
		if(millis() - _tempo_millis >= _scan_interval){                             
			_tempo_millis = millis();         
			if(digitalRead(_pin) == _trigger_up_or_down){                                              
				_count_scan_inc++;                                                         
			}
		}

		if(millis() - _tempo_millis_zero >= (_count_scan * _scan_interval) + 500){        
			_tempo_millis_zero = millis();											    
			_count_scan_inc = 0;														    															
		}  
	
		if(_alarmed == true) {			                                               
			if(millis() - _tempo_millis_alarmed >= _time_alarmed){                      
			_alarmed = false;                                                          
			}
		}
	}
}

bool sensors::is_alarmed() {                                               
	if(_count_scan_inc >= _count_scan) {		                                               
		_count_scan_inc = 0;                                                            
		_alarmed = true;                                                           
		_tempo_millis_alarmed = millis();                                           
		return true;							                                    
	}else{
		if(_alarmed == false){			         			         			    
			return false;                                               		   
		}else{
			return true;														     
		}
	}
}

void sensors::start() {
	pinMode(13,OUTPUT);
	sensor_run = true;
	while(digitalRead(_pin) == _trigger_up_or_down) {
		digitalWrite(13,HIGH); delay(50);
		digitalWrite(13,LOW); delay(50);
	}
}

void sensors::stop() {
	sensor_run = false;
}

void sensors::print(int print_interval) {
	if(millis() - _print_interval_millis >= print_interval){                              // scan dpos sensores
		_print_interval_millis = millis();         
		if(is_alarmed()) {
			Serial.println(local + ": Aberto(a)");
		}else{
			Serial.println(local + ": Fechado(a)");
		}
	}
}

void sensors::loop() {
	if(millis() - _loop_millis >= 500){                             
		_loop_millis = millis(); 
		loop_v = !loop_v;
		digitalWrite(13,loop_v);
	}
}

void sensors::var_global() {

}
