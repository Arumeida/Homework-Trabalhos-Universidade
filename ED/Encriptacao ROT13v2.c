#include <stdio.h>
#include <stdlib.h>

void rot (FILE *arc, FILE *aux, char t)
{
    char a;
    printf ("Por favor, espere um momento.");
    aux = fopen ("auxx.txt", "wt");
    do
    {
        fscanf (arc, "%c", &a);
        printf (".");
        if (!feof(arc))
        {
            if (a>=33 && a<=126)
            {
                if (a<80)
                {
                    a=a+47;
                }
                else
                {
                    a=a-47;
                }
            }
        }
        fprintf(aux,"%c",a);
    }while (!feof(arc));
    fclose (aux);
    }

int main ()
{
    FILE *arc;
    FILE *aux;
    char c[40];
    char d;
    printf ("\nDigite o nome do arquivo que deseja criptografar\n(nao se esqueça do .txt no final!)");
    scanf ("%39[^\n]", c);
    printf ("Aqui o");
    arc = fopen (c, "rt");
    aux = fopen ("auxx.txt", "wt");
    rot (arc, aux, c);
    fclose (arc);
    fclose (aux);
    arc = fopen (c, "wt");
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
