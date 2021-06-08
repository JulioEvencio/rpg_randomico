#include <stdlib.h>
#include "jogo.h"
#include "../jogador/jogador.h"
#include "../inimigo/inimigo.h"

struct Jogo
{
    int dias;
    Jogador *jogador;
    Inimigo *inimigo;
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

    if (inimigo_criar(&(*jogo)->inimigo, "Inimigo", 0, 0, 0))
    {
        jogador_liberar(&(*jogo)->jogador);
        free(*jogo);
        return -1;
    }

    (*jogo)->dias = 0;

    return 0;
}

void jogo_liberar(Jogo **jogo)
{
    inimigo_liberar(&(*jogo)->inimigo);
    jogador_liberar(&(*jogo)->jogador);
    free(*jogo);
}