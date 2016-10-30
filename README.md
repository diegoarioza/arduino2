/*
	Author: Diego Narducci Arioza
	Contato: diego.ariozza@gmail.com
*/

Construtor --> diego sensor1(1,2,3,4);

1 -> pino do sensor
2 -> tempo entre scans (em ms)
3 -> qtde de scans com retorno true para retorno true da função "sensor_is_alarmed"
4 -> tempo (em ms) que o alarme ficara como true
  
Funcoes:

	- sensor1.scan_sensor(); -> realiza o scan do sensor referente a porta.
	- sensor1.sensor_is_alarmed() -> retorna true se o alarme tiver disparado.
