	Author: Diego Narducci Arioza
	Contato: diego.ariozza@gmail.com


Construtor --> sensors sensor(1,2,3,4,5);

	1 -> pino do sensor.
	2 -> tempo entre scans (em ms).
	3 -> qtde de scans com retorno true para retorno true da função "sensor_is_alarmed".
	4 -> tempo (em ms) que o alarme ficar como true.
	5 -> local (string) - default (local)
  
Funcoes

	- sensor.local -> retorna local do sensor.
	- sensor.start() -> inicia e ativa o scan e disparo do sensor.
	- sensor.stop() -> para e desativa o scan e disparo do sensor.
	- sensor.scan_sensor() -> realiza o scan do sensor referente a porta.
	- sensor.sensor_is_alarmed() -> retorna true se o alarme tiver disparado.
