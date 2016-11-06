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

void sensors::scan() {      												// Funcao scan_sensor - scaneamento de objeto sensor
	if(sensor_run == true) {                                               				// Se o start estiver ativo
		if(millis() - _tempo_millis >= _scan_interval){                              // scan dpos sensores
			_tempo_millis = millis();         
			if(digitalRead(_pin) == _trigger_up_or_down){                                              // se o pino do sensor estiver em estado true
				_count_scan_inc++;                                                          // incremento da variavel _count_test
			}
		}

		if(millis() - _tempo_millis_zero >= (_count_scan * _scan_interval) + 500){        // zerar contagem se passar o tempo e nao for alarmado.
			_tempo_millis_zero = millis();											    //  ||
			_count_scan_inc = 0;														    //  ||															
		}  
	
		if(_alarmed == true) {			                                                // variavel auxiliar
			if(millis() - _tempo_millis_alarmed >= _time_alarmed){                      // se o disparo do alarme exceder o tempo limite de tempo ativo
			_alarmed = false;                                                           // variavel auxiliar _alarmed  em estado false
			}
		}
	}
}

bool sensors::is_alarmed() {                                               // Funcao sensor_is_alarmed - retorna true se o sensor estiver alarmado
	if(_count_scan_inc >= _count_scan) {		                                                // se a contagem exceder o numero de trues de _count
		_count_scan_inc = 0;                                                            // zera a variavel  _count
		_alarmed = true;                                                            // variavel _alarmed em estado true
		_tempo_millis_alarmed = millis();                                           // atualiza tempo
		return true;							                                    // retorno true da funcao -  se a funcao scan_sensor retornar true "_count_test" vezes 
	}else{
		if(_alarmed == false){			         			         			    // Se o sensor n estiver alarmado, o retorno sera falso.
			return false;                                               		    // Se o sensor n estiver alarmado, o retorno sera falso.
		}else{
			return true;														    // Se o sensor estiver alarmado, o retorno sera true mesmo 
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
