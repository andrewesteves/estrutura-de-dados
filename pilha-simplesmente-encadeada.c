#include <stdio.h>
#include <stdlib.h>

struct node
{
	int num;
	node *prox;	
};

void adicionarFim(node *lista)
{
	node *novo = (node *) malloc(sizeof(int));
	if(!novo)
	{
		printf("Sem memoria disponivel!");
		system("pause");
	}
	else
	{
		novo->prox = NULL;
		if(lista->prox == NULL)
		{			
			lista->prox = novo;
		}
		else
		{
			node *tmp =  lista->prox;
			while(tmp->prox != NULL)
			{
				tmp = tmp->prox;
			}
			tmp->prox = novo;
		}
		printf("Novo elemento: ");
		scanf("%d", &novo->num);
	}
}

void exibir(node *lista)
{
	if(lista->prox == NULL)
		printf("Lista vazia!");
	else
	{
		node *tmp;
		for(tmp = lista->prox; tmp != NULL; tmp = tmp->prox)
			printf("%d", tmp->num);
	}
	printf("\n\n");
	system("pause");
}

void remover(node *lista)
{
	if(lista->prox == NULL)
		printf("Lista vazia!");
	else
	{
		node *tmp = lista->prox;
		while(tmp->prox != NULL)
		{
			tmp = tmp->prox;
		}
		printf("No %d removico com sucesso!", tmp->num);
		free(tmp);
	}
	printf("\n\n");
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
}

int main(void)
{
	node *lista = (node *) malloc(sizeof(node));
	if(!lista)
	{
		printf("Sem memoria disponivel!");
		exit(1);
	}
	lista->prox = NULL;
	
	int opt;
	do
	{
		system("cls");
		printf("=======================\n");
		printf("     FILA ENCADEADA    \n");
		printf("=======================\n");
		printf(" 1 - Adicionar noh     \n");
		printf(" 2 - Remover noh       \n");
		printf(" 3 - Exibir fila       \n");
		printf(" 4 - Liberar fila      \n");
		printf(" 5 - Sair              \n");
		printf("=======================\n");
		printf("Escolha a opcao: ");
		scanf("%d", &opt);
		system("cls");
		
		switch(opt)
		{
			case 1: adicionarFim(lista);
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