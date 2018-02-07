#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int vetor[], int valor, int tamanho)
{
	int achou = 0;
	int alto = tamanho, baixo = 0, meio;
	meio = (alto + baixo) / 2;
	
	while((!achou) && (alto >= baixo))
	{
		printf("Baixo %d Meio %d Alto %d \n", baixo, meio, alto);
		if(valor == vetor[meio])
			achou = 1;
		else if(valor < vetor[meio])
			alto = meio - 1;
		else
			baixo = meio + 1;
		meio = (alto + baixo) / 2;
	}
	return ((achou) ? meio : -1);
}

int main(int argc, char** argv)
{
	int vetor[100], i;
	for(i = 0; i < 100; i++)
		vetor[i] = i;
	printf("Resultado da busca %d\n", busca_binaria(vetor, 33, 100));
	return 0;
}