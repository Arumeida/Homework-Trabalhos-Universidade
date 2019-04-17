#include <stdio.h>
#include <stdlib.h>


int main ()
{
    char t;
    int a = 0;
    char nome[40];
    char nome2[40];
    int id, hp, mana, atk;
    int id2, hp2, mana2, atk2;
    FILE *pick;
    FILE *pick2;
    FILE *pick3;
    FILE *pick4;
    FILE *pickaux;
    pick2 = fopen("picks2.txt","rt");
    pick3 = fopen("picks3.txt","rt");
    pick4 = fopen("picks4.txt","rt");
    printf ("Weeeeeeeeee\n");
    pick = fopen ("NewPick.txt","wt");
    pickaux = fopen ("Auxpick.txt", "wt");
    fscanf(pick2, "%d %s %d %d %d", &id, nome, &hp, &mana, &atk);
    fscanf(pick3, "%d %s %d %d %d", &id2, nome2, &hp2, &mana2, &atk2);
    printf ("%d %s %d %d %d\n", id, nome, hp, mana, atk);
    printf ("%d %s %d %d %d\n", id2, nome2, hp2, mana2, atk2);
    printf ("Weeeeeeeeeeeeeeeeeeee\n");
    while (!feof(pick2) && !feof(pick2))
    {
        printf ("Weeee?\n");
        if (!feof(pick2))
        {
            if (!feof(pick3))
            {
                if (id < id2)
                {
                    fprintf (pickaux,"%d %s %d %d %d\n", id, nome, hp, mana, atk);
                    fscanf (pick2, "%d %s %d %d %d", &id, nome, &hp, &mana, &atk);
                    printf ("%d %s %d %d %d\n", id, nome, hp, mana, atk);
                    printf ("Vamos!\n");
                }
                else
                {
                    printf ("chegou else \n");
                    fprintf (pickaux,"%d %s %d %d %d\n", id2, nome2, hp2, mana2, atk2);
                    printf ("aqui?\n");
                    fscanf (pick3, "%d %s %d %d %d", &id2, nome2, &hp2, &mana2, &atk2);
                    printf ("Quase la\n");
                }
            }
            else
            {
                fprintf (pickaux, "%d %s %d %d %d\n", id, nome, hp, mana, atk);
                fscanf (pick2, "%d %s %d %d %d", &id, nome, &hp, &mana,&atk);
                printf ("Maybe!\n");
            }
        }
        else
        {
            fprintf (pickaux,"%d %s %d %d %d\n", id2, nome2, hp2, mana2, atk2);
            fscanf (pick3, "%d %s %d %d %d", &id2, nome2, &hp2, &mana2, &atk2);
            printf ("Quase!\n");
        }
    }
    fclose (pickaux);
    pickaux = fopen("Auxpick.txt", "rt");
    while (!feof(pickaux) && !feof(pick4))
    {
        printf ("Weeee?\n");
        if (!feof(pickaux))
        {
            if (!feof(pick4))
            {
                if (id < id2)
                {
                    fprintf (pick,"%d %s %d %d %d\n", id, nome, hp, mana, atk);
                    fscanf (pickaux, "%d %s %d %d %d", &id, nome, &hp, &mana, &atk);
                    printf ("%d %s %d %d %d\n", id, nome, hp, mana, atk);
                    printf ("Vamos!\n");
                }
                else
                {
                    printf ("chegou else \n");
                    fprintf (pick,"%d %s %d %d %d\n", id2, nome2, hp2, mana2, atk2);
                    printf ("aqui?\n");
                    fscanf (pick4, "%d %s %d %d %d", &id2, nome2, &hp2, &mana2, &atk2);
                    printf ("Quase la\n");
                }
            }
            else
            {
                fprintf (pick, "%d %s %d %d %d\n", id, nome, hp, mana, atk);
                fscanf (pickaux, "%d %s %d %d %d", &id, nome, &hp, &mana,&atk);
                printf ("Maybe!\n");
            }
        }
        else
        {
            fprintf (pick,"%d %s %d %d %d\n", id2, nome2, hp2, mana2, atk2);
            fscanf (pick4, "%d %s %d %d %d", &id2, nome2, &hp2, &mana2, &atk2);
            printf ("Quase!\n");
        }
    }
    printf ("SAIU\n");
    fclose (pick2);
    fclose (pick3);
    fclose (pick4);
    fclose (pick);
    fclose (pickaux);
    return 0;
}
