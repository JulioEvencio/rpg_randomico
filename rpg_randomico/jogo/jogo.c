#include <stdlib.h>
#include "jogo.h"
#include "../jogador/jogador.h"

struct Jogo
{
    Jogador *jogador;
    /* Inimigo: Goblin e Ogro */
    /* NPC */
    /* Padre */
    /* Comerciante */
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

    return 0;
}

void jogo_liberar(Jogo **jogo)
{
    jogador_liberar(&(*jogo)->jogador);
    free(*jogo);
}