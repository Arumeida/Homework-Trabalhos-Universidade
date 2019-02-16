#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
	int destino;
	float custo;
	struct lista *prox;
}Lista;

int existeNo (int *vet, int no, int pos)
{
	int i;
	for (i=0; i<pos; i++)
	{
		if (vet[i]==no)
			return 1;
	}
	return 0;
}

void ImprimirCaminhosNo (Lista **g, int *vet, int pos, int destino, int no)
{
	if (vet[pos-1] == destino)
	{
		int i = 0;
		if (existeNo(vet, no, pos)==1)
		{
			while (vet[i] != destino)
			{
				printf ("%d -> ", vet[i]);
				i++;
			}
		printf ("%d \n", vet[i]);
		}
	}
	else
	{
		Lista *l = g [vet[pos-1]];
		l = l->prox;
		while (l!=NULL)
		{
			if (existe(vet, pos, l->destino) == 0)
			{
				vet[pos] = l->destino;
				ImprimirCaminhos (g, vet, pos+1, destino);
				l = l->prox;
			}
		}
}

void imprimirGrafo (Lista **g, int n)
{
	int i;
	printf ("Grafo: ");
	for (i=1; i<=n; i++)
	{
		printf ("\n %i: ");
		imprimeLista (g[i]);
	}
}

void imprimeLista (Lista *l)
{
	Lista *p = l;
	while (p!=NULL)
	{
		printf (" %i|%2f", p->destino, p->custo);
		p->prox;
	}
}

void ImprimirCaminhos (Lista **g, int *vet, int pos, int destino)
{
	if (vet[pos-1] == destino)
	{
		int i = 0;
		while (vet[i] != destino)
		{
			printf ("%d -> ", vet[i]);
			i++;
		}
	printf ("%d \n", vet[i]);
	}
	else
	{
		Lista *l = g [vet[pos-1]];
		l = l->prox;
		while (l!=NULL)
		{
			if (existe(vet, pos, l->destino) == 0)
			{
				vet[pos] = l->destino;
				ImprimirCaminhos (g, vet, pos+1, destino);
				l = l->prox;
			}
		}
}

int ExisteG (Lista **g, int origem, int destino)
{
	Lista *p = g[origem];
	while (p!=NULL)
	{
		if (p->destino == destino)
		{
			return 1;
		}
		p = p->prox;
	}
	return 0;
}

int existe (int *vet, int n, int valor)
{
    int i;
    for (i=0; i<n; i++)
    {
        if (vet[i]==valor)
        {
            return 1;
        }
    }
    return 0;
}
