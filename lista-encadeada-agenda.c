#include <stdio.h>
#include <stdlib.h>

struct agenda
{
	char nome[50];
	char email[50];
	int idade;
};

struct node
{
	struct agenda contato;
	struct node *prox;
};

void inserir(struct node *lista)
{
	struct node *novo = (struct node *) malloc(sizeof(node));
	if(!novo) exit(1);
	novo->prox = NULL;
	if(lista->prox == NULL)
		lista->prox = novo;
	else
	{
		// PILHA
		novo->prox = lista->prox;
		lista->prox = novo;
		
		/* FILA
		struct node *tmp = lista->prox;
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		tmp->prox = novo;
		*/
	}
	printf("Inserir na agenda:\n");
	printf("Nome: ");
	scanf(" %50[^\n]", &novo->contato.nome);
	printf("E-mail: ");
	scanf(" %50[^\n]", &novo->contato.email);
	printf("Idade: ");
	scanf("%d", &novo->contato.idade);
}

void remover(struct node *lista)
{
	if(lista->prox == NULL)
		printf("Fila vazia");
	else
	{
		struct node *tmp = lista->prox;
		lista->prox = tmp->prox;
		printf("\nRemovido: %s\n", tmp->contato.nome);
		free(tmp);
	}
}

void exibir(struct node *lista)
{
	if(lista->prox == NULL)
		printf("Agenda vazia");
	else
	{
		struct node *tmp = lista->prox;
		printf("Exibindo agenda:");
		while(tmp != NULL)
		{
			printf("\nNome: %s", tmp->contato.nome);
			printf("\nE-mail: %s", tmp->contato.email);
			printf("\nIdade: %d", tmp->contato.idade);
			printf("\n******************************");
			tmp = tmp->prox;
		}
	}
}

void liberar(struct node *lista)
{
	if(lista->prox == NULL)
		printf("Agenda vazia");
	else
	{
		struct node *tmp = lista->prox, *proximo;
		while(tmp != NULL)
		{
			proximo = tmp->prox;
			free(tmp);
			tmp = proximo->prox;
		}
	}
	lista->prox = NULL;
}

int main(int argc, char** argv)
{
	struct node *lista = (struct node *) malloc(sizeof(node));
	if(!lista) exit(1);
	lista->prox = NULL;
	
	inserir(lista);
	inserir(lista);
	inserir(lista);
	exibir(lista);
	remover(lista);
	exibir(lista);
	remover(lista);
	exibir(lista);
	remover(lista);
	exibir(lista);	
	liberar(lista);

	return 0;
}