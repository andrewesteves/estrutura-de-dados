#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int dado[MAX], qtd, op, i;

int inserir()
{
	if(qtd == MAX)
		printf("Pilha cheia!");
	else
	{
		for(i = qtd; i > 0; i--)
			dado[i] = dado[i - 1];
		printf("Entrar na pilha: ");
		scanf("%d", &dado[0]);
		printf("\n%d armazenado em %d\n\n", dado[0], 0);
		qtd++;
	}
	return 0;
}

int remover()
{
	if(qtd == 0)
		printf("Pilha vazia!");
	else
	{
		qtd--;
		printf("Elemento %d removido\n", dado[0]);
		for(i = 0; i < qtd; i++)
			dado[i] = dado[i + 1];
		dado[i] = 0;
	}
	return 0;
}

int exibir()
{
	if(qtd == 0)
		printf("Pilha vazia");
	else
	{
		for(i = 0; i < qtd; i++)
			printf("Posicao %d --> %d\n\n", i, dado[i]);
	}
	return 0;
}

int menu()
{
	system("cls");
	printf("=====================\n");
	printf("        PILHA        \n");
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
