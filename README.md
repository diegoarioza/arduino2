	Author: Diego Narducci Arioza
	Contato: diego.ariozza@gmail.com


Construtor --> sensors sensor(1,2,3,4);

	1 -> pino do sensor.
	2 -> tempo entre scans (em ms).
	3 -> qtde de scans com retorno true para retorno true da função "sensor_is_alarmed".
	4 -> tempo (em ms) que o alarme ficar como true.
  
Funcoes

	- sensor.local -> retorna local do sensor.

	- sensor.scan_sensor(); -> realiza o scan do sensor referente a porta.
	- sensor.sensor_is_alarmed() -> retorna true se o alarme tiver disparado.
