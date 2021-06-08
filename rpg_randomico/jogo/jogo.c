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

void jogo_imprimir_jogador(Jogo *jogo);

int jogo_jogar(void)
{
    int loop = 1;
    Jogo jogo;
    char nome[JOGADOR_NOME];

    srand(time(NULL));

    system(LIMPAR_TELA);
    puts("----------------- Aventura -----------------");

    printf("Digite seu nome de aventureiro(a): ");
    ler_string(nome, JOGADOR_NOME);

    if (jogador_criar(&jogo.jogador, nome)) return -1;

    while (loop)
    {
        system(LIMPAR_TELA);
        puts("----------------- Aventura -----------------");

        jogo_imprimir_jogador(&jogo);
        loop = 0;
    }

    jogador_liberar(&jogo.jogador);

    return 0;

}

void jogo_imprimir_jogador(Jogo *jogo)
{
    printf("Nome: %s \n", jogador_obter_nome(&jogo->jogador));
    printf("Ouro: %d \n", jogador_obter_ouro(&jogo->jogador));
    printf("Vida: %d / %d \n\n", jogador_obter_vida(&jogo->jogador), jogador_obter_vida_max(&jogo->jogador));

    if (jogador_tem_arma(&jogo->jogador)) printf("Arma: Sim \n");
    else printf("Arma: Nao \n");

    if (jogador_tem_armadura(&jogo->jogador)) printf("Armadura: Sim \n");
    else printf("Armadura: Nao \n");

    if (jogador_tem_bota(&jogo->jogador)) printf("Bota: Sim \n");
    else printf("Bota: Nao \n");

    puts("\n--------------------------------------------");
}