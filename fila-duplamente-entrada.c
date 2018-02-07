#include <stdio.h>
#include <stdlib.h>

/**
 * Fila duplamente encadeada
 * Variação 01
 */

typedef struct Node
{
	int num;
	struct Node *ante;
	struct Node *prox;
}node;

void inserir(node *lista)
{
	node *novo = (node *) malloc(sizeof(node));
	novo->prox = NULL;
	if(lista->prox == NULL)
	{
		lista->prox = novo;
		novo->ante = lista;
	}		
	else
	{
		node *tmp = lista->prox;		
		
		while(tmp->prox != NULL)
		{
			tmp = tmp->prox;
		}
		tmp->prox = novo;
		novo->ante = tmp;
	}
	printf("Inserir na fila: ");
	scanf("%d", &novo->num);
}

void remover(node *lista)
{
	if(lista->prox == NULL)
		printf("Fila vazia!");
	else
	{
		node *tmp = lista->prox;
		lista->prox = tmp->prox;
				
		if(tmp->prox != NULL)
		{
			node *proximo = tmp->prox;
			lista->prox = proximo;
			proximo->ante = lista;
		}
		
		printf("Removido: %d", tmp->num);
		free(tmp);
	}
	printf("\n");
	system("pause");
}

void exibir(node *lista)
{
	if(lista->prox == NULL)
		printf("Fila vazia!");
	else
	{
		node *tmp;
		for(tmp = lista->prox; tmp != NULL; tmp = tmp->prox)
		{
			node *anterior = tmp->ante;
			node *proximo = tmp->prox;
			if(anterior == lista)
			{
				if(proximo == NULL)
					printf("%d\n", tmp->num);
				else
					printf("%d -> %d\n", tmp->num, proximo->num);
			}
			else if(proximo == NULL)
			{
				printf("%d <- %d\n", anterior->num, tmp->num);
			}
			else
			{
				printf("%d <- %d -> %d\n", anterior->num, tmp->num, proximo->num);
			}
		}
	}
	printf("\n");
	system("pause");
}

void liberar(node *lista)
{
	node *atual = lista->prox, *proximo;
	while(atual != NULL)
	{
		proximo = atual->prox;
		free(atual);
		atual = proximo;
	}
	lista->prox = NULL;
	system("pause");
}

int main()
{
	node *lista = (node *) malloc(sizeof(node));
	lista->ante = NULL;
	lista->prox = NULL;
	
	int opt;
	do
	{
		system("cls");
		printf("=======================\n");
		printf("FILA\n");
		printf("=======================\n");
		printf(" 1 - Inserir\n");
		printf(" 2 - Remover\n");
		printf(" 3 - Exibir\n");
		printf(" 4 - Liberar\n");
		printf(" 5 - Sair\n");
		printf("=======================\n");
		printf("Escolha a opcao: ");
		scanf("%d", &opt);
		system("cls");
		
		switch(opt)
		{
			case 1: inserir(lista);
					break;
			case 2: remover(lista);
					break;
			case 3: exibir(lista);
					break;
			case 4: liberar(lista); exibir(lista);
					break;
			case 5: liberar(lista);
					break;
			default: printf("Comando invalido!\n\n");
		}
	}while(opt != 5);
	
	free(lista);
	
	return 0;	
}