#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore
	{
		int info;
		struct arvore *esq;
        struct arvore *dir;
} arvore;

void Imprimir_ordem (arvore *a)
{
	if (a==NULL)
		{
		    printf ("-");
		}
    else
    {
        Imprimir_ordem (a->esq);
        printf ("%d-", a->info);
        Imprimir_ordem (a->dir);
    }
}

arvore* remover (arvore *a, int x)
{
	if (a->info == x)
	{
		if (a->esq == NULL && a->dir == NULL)
		{
			free (a);
			return NULL;
		}
		else if (a->esq == NULL || a->dir == NULL)
		{
			arvore *aux;
			if (a->esq == NULL)
			{
				aux = a->dir;
			}
			else
			{
				aux = a->esq;
			}
		free (a);
		return aux;
		}
		else
		{
			arvore *aux = a->esq;
			while (aux->dir != NULL)
				aux = aux->dir;
            a->info = aux -> info;
			a->esq = remover (a->esq, aux->info);
			return a;
		}
	}
	else if (x < a->info)
	{
		a->esq = remover (a->esq, x);
	}
	else
	{
		a->dir = remover (a->dir, x);
	}
return a;
}

arvore* inserir (arvore *a, int x)
{
	if (a==NULL)
	{
		arvore *no = (arvore*)malloc(sizeof(arvore));
		no->info = x;
		no->esq = NULL;
		no->dir = NULL;
		return no;
	}
	else
	{
		if (x <= a->info)
			a->esq = inserir (a->esq, x);
		else
			a->dir = inserir (a->dir, x);
	}
	return a;
}

void Imprimir (arvore *a)
{
	if (a!=NULL)
	{
		printf ("%d", a->info);
		Imprimir (a->esq);
		Imprimir (a->dir);
	}
}

int buscano (arvore *a, int x)
{
    if (a!=NULL)
    {
        if (a->info = x)
        {
            return 1;
        }
        else if (a->info < x)
        {
            return buscano (a->esq, x) + 1;
        }
        else
        {
            return buscano (a->dir, x) + 1;
        }
    }
}


void ImprimirMN (arvore *a, int x, int y)
{
	if (a!=NULL)
	{
		if (a->info > x && a->info < y)
		{
			printf ("%d - ", a->info);
			ImprimirMN (a->esq, x, y);
			ImprimirMN (a->dir, x, y);
		}
		else
		{
			ImprimirMN (a->dir, x, y);
		}
	}
}

int Existe (arvore *a, int x)
{
	if (a==NULL)
	{
		return 0;
	}
	else
	{
		if (x==a->info)
			return 1;
		else
		{
			if (x < a->info)
			{
				return Existe (a->esq, x);
			}
			else
			{
				return Existe (a->dir, x);
			}
		}
	}
}

int altura (arvore *a)
{
	if (a == NULL)
	{
		return 0;
	}
	else
	{
		int he, hd;
		he = altura (a->esq);
		hd = altura (a->dir);
		if (he > hd)
			return he+1;
		else
			return hd+1;
	}
}

arvore* criar (FILE *arq)
	{
		char abre, fecha;
		int num;
		fscanf (arq, "%c", &abre);
		fscanf (arq, "%d", &num);
		if (num == -1)
		{
			fscanf(arq, "%c", &fecha);
			return NULL;
		}
		else
		{
			arvore *a = (arvore*)malloc(sizeof(arvore));
			a->info = num;
			a->esq = criar (arq);
			a->dir = criar (arq);
		fscanf (arq, "%c", &fecha);
		return a;
        }
    }

void destroyer (arvore *a)
{
    if (a!=NULL)
    {
        destroyer(a->dir);
        destroyer(a->esq);
        free (a);
    }
}

arvore* balancear (arvore *a)
{
    if (a!=NULL)
    {
        int he, hd;
        a->esq = balancear(a->esq);
        a->dir = balancear(a->dir);
        he = altura(a->esq);
        hd = altura(a->dir);
        if ((he-hd>1)||(hd-he>1))
        {
            if (he>hd)
            {
                int raiz = a->info;
                arvore *aux = a->esq;
                while(aux->dir)
                {
                    aux = aux->dir;
                }
                a->info=aux->info;
                a->esq=remover(a->esq, aux->info);
                a=inserir(a, raiz);
                a = balancear(a);
            }
            else
            {
                int raiz = a->info;
                arvore *aux = a->dir;
                while (aux->esq!=NULL)
                {
                    aux = aux->esq;
                }
                a->info = aux->info;
                a->dir = remover(a->dir, aux->info);
                a = inserir (a, raiz);
                a = balancear (a);
            }
        }
    }
    return a;
}

int main ()
{
    char fille[40];
    int choice, choicee, alt, x, resultado, f, ff, nivel=0, cont=0, w=0;
    int min, max;
    FILE *arvere;
    arvore *a = NULL;
    do
    {
        system ("cls");
        printf ("1 - Ler uma arvore de um arquivo\n");
        printf ("2 - Imprimir uma arvore\n");
        printf ("3 - Calcular a altura de uma arvore\n");
        printf ("4 - Descobrir nivel no\n");
        printf ("5 - Inserir um elemento\n");
        printf ("6 - Remover um elemento\n");
        printf ("7 - Imprimir maiores que x e menores que y\n");
        printf ("11 - Sair\n");
        scanf ("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
            case 1:
                system ("cls");
                printf ("Digite o nome do arquivo (nao se esqueca o .txt no final\n");
                scanf ("%39[^\n]", fille);
                arvere = fopen (fille, "rt");
                a = criar(arvere);
                fclose(arvere);
                a = balancear(a);
                break;

            case 2:
                system ("cls");
                Imprimir_ordem(a);
                system ("pause");
                break;

            case 3:
                system ("cls");
                alt = altura(a);
                printf ("A arvore tem altura %d\n", alt);
                system ("pause");
                break;

            case 4:
                printf ("Digite o no desejado:\n");
                scanf ("%d", &f);
                ff = buscano(a, f);
                printf ("O nivel do no e %d\n", ff);
                system ("pause");
                break;

            case 5:
                printf ("Digite o elemento que deseja inserir: \n");
                scanf ("%d", &x);
                inserir(a, x);
                a = balancear(a);
                break;

            case 6:
                printf ("Digite o elemento que deseja remover: \n");
                scanf ("%d", &choicee);
                remover(a, choicee);
                a = balancear(a);
                break;

            case 7:
                printf ("Digite os o menor e maior numero: \n");
                scanf ("%d", &min);
                scanf ("%d", &max);
                ImprimirMN(a, min, max);
                system ("pause");
                break;

            case 8:
                a = balancear(a);
                Imprimir_ordem(a);
                printf ("\n");
                system ("pause");
                break;

            case 11:
                system ("cls");
                destroyer (a);
                break;

            default:
                system ("cls");
                printf ("Opcao invalida\n");
                break;

        }
    } while (choice!=11);
return 0;
}
