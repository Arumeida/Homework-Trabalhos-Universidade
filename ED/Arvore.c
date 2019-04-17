#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore
	{
		int info;
		struct arvore *esq;
	struct arvore *dir;
} arvore;

void Imprimir_pre (arvore *a)
{
	if (a==NULL)
		{
		    printf ("-");
		}
    else
    {
        printf ("%d-", a->info);
        Imprimir_pre (a->esq);
        Imprimir_pre (a->dir);
    }
}

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
void Imprimir_pos (arvore *a)
{
	if (a==NULL)
		{
		    printf ("-");
		}
    else
    {
        Imprimir_pos (a->esq);
        Imprimir_pos (a->dir);
        printf ("%d-", a->info);
    }
}

void Imprimir_not (arvore *a)
{
    if (a==NULL)
        printf ("(-1)");
    else
    {
        printf ("(");
        printf ("%d", a->info);
        Imprimir_not (a->esq);
        Imprimir_not (a->dir);
        printf (")");
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

int conta_oco (arvore* a, int x)
{
    if (a==NULL)
        return 0;
    else
    {
        if (a->info==x)
            return 1+conta_oco(a->dir,x)+conta_oco(a->esq,x);
        else
            return 0+conta_oco(a->dir,x)+conta_oco(a->esq,x);
    }
}

int main ()
{
    char fille[40];
    int choice, choicee, alt, x, resultado;
    FILE *arvere;
    arvore *a = NULL;
    do
    {
        system ("cls");
        printf ("1 - Ler uma arvore de um arquivo\n");
        printf ("2 - Imprimir uma arvore\n");
        printf ("3 - Calcular a altura de uma arvore\n");
        printf ("4 - Verificar se um elemento existe na arvore\n");
        printf ("5 - Contar o numero de ocorrencias de um elemento na arvore\n");
        printf ("6 - Sair\n");
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
                break;

            case 2:
                system ("cls");
                printf ("De qual forma deseja imprimir\n1 - Pre-ordem\n");
                printf ("2 - Em ordem\n3 - Pos-ordem\n4 - Notacao\n");
                scanf("%d", &choicee);
                switch (choicee)
                {
                    case 1:
                        system ("cls");
                        Imprimir_pre(a);
                        system ("pause");
                        break;

                    case 2:
                        system ("cls");
                        Imprimir_ordem(a);
                        system ("pause");
                        break;

                    case 3:
                        system ("cls");
                        Imprimir_pos(a);
                        system ("pause");
                        break;

                    case 4:
                        system ("cls");
                        Imprimir_not(a);
                        system ("pause");
                        break;

                    Default:
                        system ("cls");
                        printf ("Opcao invalida \n");
                        system ("pause");
                        break;
                }
                break;

            case 3:
                system ("cls");
                alt = altura(a);
                printf ("A arvore tem altura %d\n", alt);
                system ("pause");
                break;

            case 4:
                system ("cls");
                printf ("Digite o elemento desejado\n");
                scanf("%d",&x);
                resultado = conta_oco(a,x);
                if (resultado==0)
                {
                    printf("O elemento nao existe na arvore\n");
                    system ("pause");
                }
                else
                {
                    printf ("O elemento existe na arvore\n");
                    system ("pause");
                }
                break;

            case 5:
                system ("cls");
                printf ("Digite o elemento desejado\n");
                scanf("%d",&x);
                resultado = conta_oco(a,x);
                printf ("O elemento aparece %d vezes na arvore\n", resultado);
                system ("pause");
                break;

            case 6:
                system ("cls");
                destroyer (a);
                break;

            default:
                system ("cls");
                printf ("Opcao invalida\n");
                break;

        }
    } while (choice!=6);
return 0;
}
