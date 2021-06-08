#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../cabecalho.h"
#include "jogo.h"
#include "../jogador/jogador.h"
#include "../inimigo/inimigo.h"

struct Jogo
{
    int dias;
    Jogador *jogador;
    Inimigo *inimigo;
};
typedef struct Jogo Jogo;

int jogo_jogar(void)
{
    int loop = 1;
    Jogo jogo;
    char nome[JOGADOR_NOME];

    system(LIMPAR_TELA);
    srand(time(NULL));

    puts("----------------- Aventura -----------------");

    printf("Digite seu nome de aventureiro(a): ");
    ler_string(nome, JOGADOR_NOME);

    if (jogador_criar(&jogo.jogador, nome)) return -1;

    while (loop)
    {
        loop = 0;
    }

    jogador_liberar(&jogo.jogador);

    return 0;

}