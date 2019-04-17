#include <stdio.h>
#include <stdlib.h>

typedef struct hero {
    int id;
    char nome[40];
    int hp;
    int mana;
    int atk;
} Hero;

void remover_hero (FILE* pick, int ex)
{
    Hero aux;
    FILE* picks_aux=fopen("picks_aux.dat","wb");
    while(fread(&aux,sizeof(Hero),1,pick)>0){
    	if(aux.id!=ex){
    		fwrite(&aux,sizeof(struct hero),1,picks_aux);
    	}
    }
    fclose(pick);
    fclose(picks_aux);
    remove("picks.dat");
    rename("picks_aux.dat", "picks.dat");
}


int conta_hero (FILE* pick)
{
    pick=fopen("picks.dat","rb");
	int contador=0;
	Hero h;
	while (fread(&h,sizeof(Hero),1,pick)>0){
		contador++;
	}
	fclose(pick);
	return contador;
}

int verificar_id (FILE* pick, int idd)
{
    Hero h;
    pick = fopen ("picks.dat","rb");
    while(fread(&h,sizeof(Hero),1,pick)>0){
		if(idd==h.id)
          return 1;
    }
	return 0;
return 0;
}

void imprimir_hero(FILE* pick)
{
    pick = fopen ("picks.dat","rb");
    Hero h;
    while(fread(&h, sizeof(Hero), 1, pick)>0)
    {
        printf ("Id: %d\nNome: %s\nHP: %d\nMana: %d\nAtk: %d\n\n", h.id, h.nome, h.hp, h.mana, h.atk);
    }
    fclose (pick);
}
void inserir_hero (FILE *pick)
{
    Hero *h;
    h = (Hero*)malloc(sizeof(Hero));
    pick = fopen ("picks.dat", "a+b");
    printf ("Digite o ID do Hero\n");
    scanf ("%d", &h->id);
    fflush(stdin);
    printf ("Digite o nome do hero\n");
    scanf ("%s", h->nome);
    fflush(stdin);
    printf ("Digite a quantidade de HP do Hero\n");
    scanf ("%d", &h->hp);
    fflush(stdin);
    printf ("Digite a quantidade de Mana do Hero\n");
    scanf ("%d", &h->mana);
    fflush(stdin);
    printf ("Digite o ataque do Hero\n");
    scanf ("%d", &h->atk);
    fflush(stdin);
    fwrite(h,sizeof(Hero),1,pick);
    fclose (pick);
}

int main ()
{
    FILE *pick;
    int cont = 0;
    int choice;
    int po, poo;
    pick = fopen ("picks.dat", "wb");
    if (pick == NULL) {
        printf ("Erro na abertura do arquivo\n");
        return 1;
    }
    do
    {
        printf ("--> 1 - Inserir um novo Hero\n");
        printf ("--> 2 - Imprimir todos os heros existentes no arquivo\n");
        printf ("--> 3 - Verificar se determinado item (identificador) existe no arquivo\n");
        printf ("--> 4 - Contar o número de Heros existentes no arquivo\n");
        printf ("--> 5 - Remover um determinado Hero\n");
        printf ("--> 6 - Sair\n");
        printf ("Digite a opcao desejada:\n");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1:
                system ("cls");
                inserir_hero(pick);
                system ("cls");
                break;
            case 2:
                system ("cls");
                pick = fopen("picks.dat", "rb");
                imprimir_hero(pick);
                system ("pause");
                system ("cls");
                break;
            case 3:
                system ("cls");
                int iddd;
                int res;
                pick = fopen("picks.dat", "rb");
                printf ("\nDigite o numero do ID desejado: ");
                scanf("%d", &iddd);
                res = verificar_id(pick, iddd);
                if (res == 1)
                    printf ("\nO Hero existe no arquivo\n");
                else if (res == 0)
                    printf("\nO Hero nao existe no arquivo\n");
                system("pause");
                system ("cls");
                break;
            case 4:
                system ("cls");
                pick = fopen("picks.dat", "rb");
                cont = conta_hero(pick);
                printf("\nTem %d Heros na lista\n", cont);
                system("pause");
                system ("cls");
                break;
            case 5:
                printf("Digite o numero do hero a ser removido: ");
				scanf("%d",&po);
				poo=verificar_id(pick,po);
				if(poo==1){
					remover_hero(pick,po);
					printf("\nRemovido!\n\n");
				}
				else
					printf("\nHero nao existe\n");
				system ("pause");
                break;
            case 6:
                return 0;
            default:
                printf ("Opcao invalida\n");
                break;
        }
    }while (choice =! 0);
    fclose(pick);
    return 0;
}
