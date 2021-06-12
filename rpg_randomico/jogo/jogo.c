#include <stdio.h>
#include <stdlib.h>
#include "../cabecalho.h"
#include "jogo.h"
#include "../jogador/jogador.h"
#include "../inimigo/inimigo.h"

#define JOGO_GERAR_TERRENO rand() % 5
#define JOGO_GERAR_ENCONTRO rand() % 5
#define JOGO_GERAR_FRASE rand() % 3

enum Terrenos
{
    TERRENO_CIDADE,
    TERRENO_DESERTO,
    TERRENO_FLORESTA,
    TERRENO_PLANICE,
    TERRENO_MASMORRA
};

enum Encontros
{
    ENCONTRO_ALDEAO,
    ENCONTRO_COMERCIANTE,
    ENCONTRO_PADRE,
    ENCONTRO_INIMIGO,
    ENCONTRO_NADA
};

struct Jogo
{
    int dias;
    Jogador *jogador;
    Inimigo *inimigo;
};
typedef struct Jogo Jogo;

void jogo_imprimir_jogador(Jogo *jogo);
char *jogo_gerar_frase_aldeao(void);
void jogo_encontrar_padre(Jogo *jogo);

int jogo_jogar(void)
{
    int loop = 1;
    Jogo jogo = {0, NULL, NULL};

    system(LIMPAR_TELA);
    puts("----------------- Aventura -----------------");

    {
        char nome[JOGADOR_NOME];

        printf("Digite seu nome de aventureiro(a): ");
        ler_string(nome, JOGADOR_NOME);

        if (jogador_criar(&jogo.jogador, nome)) return -1;
    }

    while (loop)
    {
        system(LIMPAR_TELA);
        puts("----------------- Aventura -----------------");

        jogo.dias++;

        jogo_imprimir_jogador(&jogo);

        switch (JOGO_GERAR_TERRENO)
        {
            case TERRENO_CIDADE:
                printf("Voce chegou a uma cidade ");
                break;

            case TERRENO_DESERTO:
                printf("Voce chegou a um deserto ");
                break;

            case TERRENO_FLORESTA:
                printf("Voce chegou a uma floresta ");
                break;

            case TERRENO_PLANICE:
                printf("Voce chegou a uma planice ");
                break;

            case TERRENO_MASMORRA:
                printf("Voce chegou a uma masmorra ");
                break;
        }

        switch (JOGO_GERAR_ENCONTRO)
        {
            case ENCONTRO_ALDEAO:
                printf("e encontrou um aldeao... \n");
                puts("\n--------------------------------------------\n");
                puts(jogo_gerar_frase_aldeao());
                puts("\n--------------------------------------------");
                break;

            case ENCONTRO_COMERCIANTE:
                printf("e encontrou um comerciante... \n");
                puts("\n--------------------------------------------\n");
                puts("Comerciante...");
                puts("\n--------------------------------------------");
                break;

            case ENCONTRO_PADRE:
                printf("e encontrou um padre... \n");
                puts("\n--------------------------------------------\n");
                jogo_encontrar_padre(&jogo);
                puts("\n--------------------------------------------");
                break;

            case ENCONTRO_INIMIGO:
                printf("e encontrou um inimigo... \n");
                puts("\n--------------------------------------------\n");
                puts("Inimigo...");
                puts("\n--------------------------------------------");
                break;

            case ENCONTRO_NADA:
                printf("e encontrou nada... \n");
                break;
        }

        if (ler_numero(&loop)) loop = -1;

        pausar_tela("Pressione enter para continuar...");
    }

    jogador_liberar(&jogo.jogador);

    puts("\n--------------------------------------------");
    printf("Voce sobreviveu por %d dias \n", jogo.dias);

    return 0;

}

void jogo_imprimir_jogador(Jogo *jogo)
{
    printf("Nome: %s \n", jogador_obter_nome(&jogo->jogador));
    printf("Dia: %d \n", jogo->dias);
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

char *jogo_gerar_frase_aldeao(void)
{
    switch (JOGO_GERAR_FRASE)
    {
        case 0:
            return "Voce nao eh bem vindo aqui!";

        case 1:
            return "Seu fim esta proximo!";

        case 2:
            return "Um heroi, eh disso que o mundo precisa!";
    }
}

void jogo_encontrar_padre(Jogo *jogo)
{
    if (jogador_obter_vida(&jogo->jogador) != jogador_obter_vida_max(&jogo->jogador))
    {
        puts("Vou curar suas feridas! Ate logo, bravo aventureiro!");
        jogador_alterar_vida(&jogo->jogador, jogador_obter_vida_max(&jogo->jogador));
    }
    else
    {
        puts("Cuidado com os monstros desse mundo!");
    }
}