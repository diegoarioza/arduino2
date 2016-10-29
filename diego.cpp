

#include "Arduino.h"
#include "diego.h"


diego::diego(int pin, int time_scan_sensor, int count, int time_alarmed)
{
    pinMode(pin, INPUT);
	_pin = pin;
	_time_scan_sensor = time_scan_sensor;
	_count = count;
	_time_alarmed = time_alarmed;
	// ----
	_count_test = 0;
	_tempo_millis = 0;
	_tempo_millis_alarmed = 0;
	_tempo_millis_zero = 0;
	_alarmed = false;
}

bool diego::scan_sensor() {                                                     // Funcao scan_sensor - scaneamento de objeto sensor
	if(millis() - _tempo_millis >= _time_scan_sensor){                              // scan dpos sensores
		_tempo_millis = millis();                                                   // atualizar tempo do scan

		if(digitalRead(_pin) == true){                                              // se o pino do sensor estiver em estado true
			_count_test++;                                                          // incremento da variavel _count_test
		}
	}

	if(millis() - _tempo_millis_zero >= (_count * _time_scan_sensor) + 500){        // zerar contagem se passar o tempo e nao for alarmado.
		_tempo_millis_zero = millis();											    //  ||
		_count_test = 0;														    //  ||															
	}  
	
	if(_alarmed == true) {			                                                // variavel auxiliar
		if(millis() - _tempo_millis_alarmed >= _time_alarmed){                      // se o disparo do alarme exceder o tempo limite de tempo ativo
		_alarmed = false;                                                           // variavel auxiliar _alarmed  em estado false
		}
	}
}

bool diego::sensor_is_alarmed() {                                               // Funcao sensor_is_alarmed - retorna true se o sensor estiver alarmado
	if(_count_test >= _count) {		                                                // se a contagem exceder o numero de trues de _count
		_count_test = 0;                                                            // zera a variavel  _count
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

/*
Construtor --> parametros
	1 -> pino do sensor
	2 -> tempo entre scans
	3 -> qtde de scans com retorno true para retorno true da função "sensor_is_alarmed"
	4 -> tempo em ms para o retorno true da funcao "sensor_is_alarmed" apos o disparo

*/

