#include <stdlib.h>
#include <string.h>
#include "inimigo.h"

enum
{
    INIMIGO_NOME = 31
};

struct Inimigo
{
    char nome[INIMIGO_NOME];
    int vida_max;
    int vida;
    int ataque;
    int velocidade;
};

int inimigo_criar(Inimigo **inimigo, char *nome, int vida, int ataque, int velocidade)
{
    *inimigo = malloc(sizeof **inimigo);

    if (*inimigo == NULL) return -1;

    strcpy((*inimigo)->nome, nome);

    (*inimigo)->vida_max = vida;
    (*inimigo)->vida = (*inimigo)->vida_max;
    (*inimigo)->ataque = ataque;
    (*inimigo)->velocidade = velocidade;

    return 0;
}

void inimigo_liberar(Inimigo **inimigo)
{
    free(*inimigo);
}

char *inimigo_obter_nome(Inimigo **inimigo)
{
    return (*inimigo)->nome;
}

int inimigo_obter_vida_max(Inimigo **inimigo)
{
    return (*inimigo)->vida_max;
}

int inimigo_obter_vida(Inimigo **inimigo)
{
    return (*inimigo)->vida;
}

void inimigo_alterar_vida(Inimigo **inimigo, int vida)
{
    (*inimigo)->vida = vida;
    if ((*inimigo)->vida < 0) (*inimigo)->vida = 0;
}

int inimigo_obter_ataque(Inimigo **inimigo)
{
    return (*inimigo)->ataque;
}

int inimigo_obter_velocidade(Inimigo **inimigo)
{
    return (*inimigo)->velocidade;
}