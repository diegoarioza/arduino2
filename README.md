	Author: Diego Narducci Arioza
	Contato: diego.ariozza@gmail.com


Construtor --> sensors sensor(1,2,3,4,5,6);

	1 -> pino do sensor.
	2 -> tempo entre scans (em ms).
	3 -> qtde de scans com retorno true para retorno true da função "is_alarmed()".
	4 -> tempo (em ms) que o alarme ficar como true.
	5 -> local (string)
	6 -> disparo do input do sensor, input em True ou False ( default = false ).
  
Funcoes

	- sensor.local -> retorna local do sensor.
	- sensor.start() -> inicia e ativa o scan e disparo do sensor.
	- sensor.stop() -> para e desativa o scan e disparo do sensor.
	- sensor.scan() -> realiza o scan do sensor referente a porta.
	- sensor.is_alarmed() -> retorna true se o alarme tiver disparado.
	- sensor.print(1) -> imprime na saida Serial o local + estado atual do alarme.
		1 -> tempo (em ms) de impressao na saida serial.
	- sensor.loop() -> coloca o led 13 do arduino para piscal a cada 500ms, indicação de programa rodando.
