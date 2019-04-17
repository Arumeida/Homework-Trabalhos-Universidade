#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore
	{
		int info;
		struct arvore *esq;
	struct arvore *dir;
} arvore;

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

int verifica_avl(arvore *a){
	if(a==NULL)
		return 1;
	else{
		arvore *e,*d;
		e=a->esq;
		d=a->dir;
		if (e!=NULL && d!=NULL){
			if(e->info<=a->info && a->info<d->info)
				return 1*verifica_avl(a->esq)*verifica_avl(a->dir);
			else
				return 0;
		}
		else{
			if(e==NULL || d==NULL)
				if(e==NULL)
					return 1*verifica_avl(a->dir);
				else{
					if (d==NULL)
						return 1*verifica_avl(a->esq);
				}
			return 1;
		}
	}
}



int verifica_balancear (arvore* a){
	int he,hd;
	if(a==NULL)
		return 0;
	else{
		he=altura(a->esq);
		hd=altura(a->dir);
		if(he>hd+1)
			return 1+verifica_balancear(a->esq);
		else{
			if(hd>he+1)
				return 1+verifica_balancear(a->dir);
			else
				return 0;
		}
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

int main ()
{
    char fille [40];
    FILE *arvere;
    arvore *a = NULL;
    int b, c, d;
    do
    {
        printf ("Digite a opção desejada\n");
        printf ("1 - Ler uma arvore de um arquivo\n");
        printf ("2 - Verificar se a arvore esta balanceada\n");
        printf ("3 - Verificar se a arvore esta ordenada\n");
        printf ("11 - sair\n");
        scanf ("%d", &b);
        switch (b)
        {
        case 1:
            printf ("Digite o nome do arquivo que deseja abrir\n(Nao se esqueca do .txt no final!)\n");
            scanf ("%39[^\n]", fille);
            arvere = fopen (fille, "rt");
            a = criar(arvere);
            system ("cls");
            break;

        case 2:
            c = verifica_balancear(a);
            if (c==0)
            {
                printf ("A arvore esta balanceada\n");
                system ("pause");
                system ("cls");
            }
            else
            {
                printf ("A arvore nao esta balanceada");
                system ("pause");
                system ("cls");
            }
            break;

        case 3:
            d = verifica_avl(a);
            if (d==1)
            {
                printf ("A arvore esta ordenada\n");
                system ("pause");
                system ("cls");
            }
            else
            {
                printf ("A arvore nao esta ordenada\n");
                system ("pause");
                system ("cls");
            }
            break;

        case 11:
            destroyer(a);
            break;

        default:
            system ("cls");
            printf ("Opcao invalida \n");
            system ("pause");
            break;
        }
    }while (b!=11);
}
