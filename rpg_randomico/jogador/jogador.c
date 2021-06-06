#include <stdlib.h>
#include <string.h>
#include "jogador.h"

struct Jogador
{
    char nome[JOGADOR_NOME];
    int ouro;

    int vida;
    int ataque;
    int velocidade;

    int arma;
    int armadura;
    int bota;
};

int jogador_criar(Jogador **jogador, char *nome)
{
    *jogador = malloc(sizeof **jogador);

    if (*jogador == NULL) return -1;

    strcpy((*jogador)->nome, nome);
    (*jogador)->ouro = 0;

    (*jogador)->vida = 20;
    (*jogador)->ataque = 5;
    (*jogador)->velocidade = 2;

    (*jogador)->arma = 0;
    (*jogador)->armadura = 0;
    (*jogador)->bota = 0;

    return 0;
}

void jogador_liberar(Jogador **jogador)
{
    free(*jogador);
}

char *jogador_obter_nome(Jogador **jogador)
{
    return (*jogador)->nome;
}

int jogador_obter_ouro(Jogador **jogador)
{
    return (*jogador)->ouro;
}
void jogador_alterar_ouro(Jogador **jogador, int ouro)
{
    (*jogador)->ouro = ouro;
}

int jogador_obter_vida(Jogador **jogador)
{
    return (*jogador)->vida;
}

int jogador_obter_ataque(Jogador **jogador)
{
    return (*jogador)->ataque;
}

int jogador_obter_velocidade(Jogador **jogador)
{
    return (*jogador)->velocidade;
}

int jogador_tem_arma(Jogador **jogador)
{
    return (*jogador)->arma == 1;
}

void jogador_adicionar_arma(Jogador **jogador)
{
    (*jogador)->arma = 1;
    (*jogador)->ataque += 5;
}

int jogador_tem_armadura(Jogador **jogador)
{
    return (*jogador)->armadura == 1;
}

void jogador_adicionar_armadura(Jogador **jogador)
{
    (*jogador)->armadura = 1;
    (*jogador)->vida += 20;
}

int jogador_tem_bota(Jogador **jogador)
{
    return (*jogador)->bota == 1;
}

void jogador_adicionar_bota(Jogador **jogador)
{
    (*jogador)->bota = 1;
    (*jogador)->velocidade += 3;
}