#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int dado[MAX], qtd, op, i;

int inserir()
{
	if(qtd == MAX)
		printf("Fila cheia!");
	else
	{
		printf("Entrar na fila: ");
		scanf("%d", &dado[qtd]);
		printf("\n%d armazenado em %d\n\n", dado[qtd], qtd);
		qtd++;
	}	
	return qtd;
}

int remover()
{
	if(qtd == 0)
		printf("Fila vazia!");
	else
	{
		qtd--;
		printf("Elemento %d removido\n", dado[0]);
		for(i = 0; i < qtd; i++)
			dado[i] = dado[i + 1];
		dado[i] = 0;
	}
	return qtd;
}

int exibir()
{
	if(qtd == 0)
		printf("Fila vazia!");
	else
	{
		for(i = 0; i < qtd; i++)
			printf("Posicao %d --> %d\n\n", i, dado[i]);
	}
	return qtd;
}

int menu()
{
	system("cls");
	printf("=====================\n");
	printf("        FILA         \n");
	printf("=====================\n");
	printf("    1 - Inserir      \n");
	printf("    2 - Remover      \n");
	printf("    3 - Exibir       \n");
	printf("    4 - Sair         \n");
	printf("=====================\n");
	printf(" Selecione sua opcao:  ");
	scanf("%d", &op);
	system("cls");
	
	switch(op) {
		case 1: 
			inserir();
			break;
		case 2:
			remover();
			break;
		case 3:
			exibir();
			break;
	}
	return 0;
}

int main()
{
	while(op != 4) {
		menu();
		system("pause");
	}		
}