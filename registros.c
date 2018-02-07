#include <stdio.h>

int main()
{
	struct horario
	{
		int hora;
		int minuto;
		int segundo;
		int aviso() {
			printf("Aviso\n");   
		    return 0;	
		};
	};
	
	struct horario inicio;
	
	inicio.hora = 8;
	inicio.minuto = 10;
	inicio.segundo = 20;
	inicio.aviso();
	
	printf("Inicio: %i:%i:%i\n", inicio.hora, inicio.minuto, inicio.segundo);
	getchar();
	
	return 0;
}