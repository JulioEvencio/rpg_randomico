#include <stdlib.h>
#include "jogo.h"
#include "../jogador/jogador.h"

struct Jogo
{
    int dias;
    Jogador *jogador;
    /* Inimigo: Goblin e Ogro */
};

int jogo_criar(Jogo **jogo)
{
    *jogo = malloc(sizeof **jogo);

    if (*jogo == NULL) return -1;

    if (jogador_criar(&(*jogo)->jogador, "Jogador"))
    {
        free(*jogo);
        return -1;
    }

    (*jogo)->dias = 0;

    return 0;
}

void jogo_liberar(Jogo **jogo)
{
    jogador_liberar(&(*jogo)->jogador);
    free(*jogo);
}