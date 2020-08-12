/*  Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*  Struct dos monstros */
typedef struct Lista_monstros
{
    char nome[100];
    int ataque;
    int vida;
    int velocidade;
}Base_monstros;
Base_monstros monstros[2];

/*  Lista de monstros */
/*  Ladrao */
strcpy(monstros[0].nome, "Ladrao");
monstros[0].ataque = 3;
monstros[0].vida = 3;
monstros[0].velocidade = 3;
/*  Ogro */
strcpy(monstros[1].nome, "Ogro");
monstros[1].ataque = 2;
monstros[1].vida = 5;
monstros[1].velocidade = 1;

/*  Funcoes */

/*  Funcao main */
int main()
{
    /*  */

    return 0;
}
