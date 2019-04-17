#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rot (FILE *arc, FILE *aux, char t)
{
    char a;
    printf ("Por favor, espere um momento.");
    aux = fopen ("auxx.txt", "wt");
    while (fscanf (arc, "%c", &a) == 1)
    {
        if (feof(arc))
            break;
        printf (".");
            if (a>=97 && a<=122)
            {
                if (a<110)
                {
                    a=a+13;
                }
                else
                {
                    a=a-13;
                }
            }
            else if (a>=65 && a <=90)
            {
                if (a<78)
                    a=a+13;
                else
                    a=a-13;
            }
            fprintf(aux,"%c",a);
    }
    fclose (aux);
}

int main ()
{
    FILE *arc;
    FILE *aux;
    char c[50];
    char txt[] = ".txt";
    char daux[] = "_aux";
    char fin[50];
    char d;
    printf ("\nDigite o nome do arquivo que deseja criptografar: ");
    scanf ("%39[^\n]", c);
    strcpy(fin, c);
    strcat(c, txt);
    printf ("\nO nome de arquivo de entrada e: %s\n",c);
    arc = fopen (c, "rt");
    aux = fopen ("auxx.txt", "wt");
    rot (arc, aux, c);
    fclose (arc);
    fclose (aux);
    strcat(fin,daux);
    strcat(fin,txt);
    printf ("\nO nome do arquivo de saida e: %s\n\n", fin);
    arc = fopen (fin, "wt");
    aux = fopen ("auxx.txt", "r+");
    rewind (aux);
    do
    {
        fscanf (aux, "%c", &d);
        fprintf(arc,"%c",d);
    }while (!feof(aux));
    fclose (arc);
    fclose (aux);
    aux = fopen ("auxx.txt", "wt");
    fclose (aux);
    printf ("\nProcesso concluido com sucesso!");
    return 0;
}
