#include <stdlib.h>
#include <string.h>
#include "npc.h"

struct Npc
{
    char frase1[29];
    char frase2[25];
    char frase3[37];
};

int npc_criar(Npc **npc)
{
    *npc = malloc(sizeof **npc);

    if (*npc == NULL) return -1;

    strcpy((*npc)->frase1, "Voce nao eh bem vindo aqui!");
    strcpy((*npc)->frase2, "A morte esta proxima...");
    strcpy((*npc)->frase3, "Sorte realmente existe nesse jogo?");

    return 0;
}

void npc_liberar(Npc **npc)
{
    free(*npc);
}

char *npc_obter_frase(Npc **npc, int frase)
{
    if (frase == 1) return (*npc)->frase1;
    else if (frase == 2) return (*npc)->frase2;
    else return (*npc)->frase3;
}