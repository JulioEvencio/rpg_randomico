#include <stdio.h>
#include <stdlib.h>
#include "../cabecalho.h"
#include "jogo.h"
#include "../jogador/jogador.h"
#include "../inimigo/inimigo.h"

#define JOGO_GERAR_TERRENO rand() % 5
#define JOGO_GERAR_ENCONTRO rand() % 5
#define JOGO_GERAR_FRASE rand() % 3
#define JOGO_GERAR_ITEM rand() % 3
#define JOGO_GERAR_INIMIGO rand() % 2

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
    ENCONTRO_SACERDOTE,
    ENCONTRO_INIMIGO,
    ENCONTRO_NADA
};

enum Comerciante
{
    COMERCIANTE_ARMA,
    COMERCIANTE_ARMADURA,
    COMERCIANTE_BOTA,

    COMERCIANTE_QUER_COMPRAR = 1,
    COMERCIANTE_NAO_QUER_COMPRAR = 2,

    COMERCIANTE_PRECO_ARMA = 20,
    COMERCIANTE_PRECO_ARMADURA = 20,
    COMERCIANTE_PRECO_BOTA = 10
};

enum Dados_Inimigos
{
    GOBLIN_VIDA = 10,
    GOBLIN_ATAQUE = 3,
    GOBLIN_VELOCIDADE = 3,

    OGRO_VIDA = 20,
    OGRO_ATAQUE = 5,
    OGRO_VELOCIDADE = 1
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
void jogo_encontrar_sacerdote(Jogo *jogo);
void jogo_encontrar_comerciante(Jogo *jogo);
void jogo_encontrar_inimigo(Jogo *jogo);
void jogo_balhar(Jogo *jogo);
void jogo_balhar_imprimir_dados(Jogo *jogo);

int jogo_jogar(void)
{
    Jogo jogo = {0, NULL, NULL};

    system(LIMPAR_TELA);
    puts("----------------- Aventura -----------------");

    {
        char nome[JOGADOR_NOME];

        printf("Digite seu nome de aventureiro(a): ");
        ler_string(nome, JOGADOR_NOME);

        if (jogador_criar(&jogo.jogador, nome)) return -1;
    }

    while (jogador_obter_vida(&jogo.jogador) > 0)
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
                jogo_encontrar_comerciante(&jogo);
                puts("\n--------------------------------------------");
                break;

            case ENCONTRO_SACERDOTE:
                printf("e encontrou um sacerdote... \n");
                puts("\n--------------------------------------------\n");
                jogo_encontrar_sacerdote(&jogo);
                puts("\n--------------------------------------------");
                break;

            case ENCONTRO_INIMIGO:
                printf("e encontrou um inimigo... \n");
                puts("\n--------------------------------------------\n");
                pausar_tela("Pressione enter para continuar...");
                jogo_encontrar_inimigo(&jogo);
                break;

            case ENCONTRO_NADA:
                printf("e encontrou nada... \n");
                puts("\n--------------------------------------------\n");
                break;
        }

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
            return "Aldeao: voce nao eh bem vindo aqui!";

        case 1:
            return "Aldeao: seu fim esta proximo!";

        case 2:
            return "Aldeao: um heroi, eh disso que o mundo precisa!";
    }
}

void jogo_encontrar_comerciante(Jogo *jogo)
{
    int opcao;

    puts("Comerciante: Bem vindo!");

    switch (JOGO_GERAR_ITEM)
    {
        case COMERCIANTE_ARMA:
            printf("Gostaria de comprar uma espada por %d moedas de ouro? \n", COMERCIANTE_PRECO_ARMA);
            puts("1. Sim");
            puts("2. Nao");
            printf("Opcao: ");

            if (ler_numero(&opcao)) opcao = -1;

            switch(opcao)
            {
                case COMERCIANTE_QUER_COMPRAR:
                    if (jogador_obter_ouro(&jogo->jogador) >= COMERCIANTE_PRECO_ARMA)
                    {
                        if (!jogador_tem_arma(&jogo->jogador))
                        {
                            puts("Hehe, volte sempre!");
                            jogador_alterar_ouro(&jogo->jogador, jogador_obter_ouro(&jogo->jogador) - COMERCIANTE_PRECO_ARMA);
                            jogador_adicionar_arma(&jogo->jogador);
                        }
                        else
                        {
                            puts("Voce ja esta equipado com uma espada!");
                        }
                    }
                    else
                    {
                        puts("Sem dinherio, sem arma!");
                    }
                    break;

                case COMERCIANTE_NAO_QUER_COMPRAR:
                    puts("Que pena...");
                    break;

                default:
                    puts("Nao brinque comigo, quer saber? Vou embora que ganho mais!");
            }
            break;

        case COMERCIANTE_ARMADURA:
            printf("Gostaria de comprar uma armadura por %d moedas de ouro? \n", COMERCIANTE_PRECO_ARMADURA);
            puts("1. Sim");
            puts("2. Nao");
            printf("Opcao: ");

            if (ler_numero(&opcao)) opcao = -1;

            switch(opcao)
            {
                case COMERCIANTE_QUER_COMPRAR:
                    if (jogador_obter_ouro(&jogo->jogador) >= COMERCIANTE_PRECO_ARMADURA)
                    {
                        if (!jogador_tem_armadura(&jogo->jogador))
                        {
                            puts("Hehe, volte sempre!");
                            jogador_alterar_ouro(&jogo->jogador, jogador_obter_ouro(&jogo->jogador) - COMERCIANTE_PRECO_ARMADURA);
                            jogador_adicionar_armadura(&jogo->jogador);
                        }
                        else
                        {
                            puts("Voce ja esta equipado com uma armadura!");
                        }
                    }
                    else
                    {
                        puts("Sem dinherio, sem armadura!");
                    }
                    break;

                case COMERCIANTE_NAO_QUER_COMPRAR:
                    puts("Que pena...");
                    break;

                default:
                    puts("Nao brinque comigo, quer saber? Vou embora que ganho mais!");
            }
            break;

        case COMERCIANTE_BOTA:
            printf("Gostaria de comprar uma bota por %d moedas de ouro? \n", COMERCIANTE_PRECO_BOTA);
            puts("1. Sim");
            puts("2. Nao");
            printf("Opcao: ");

            if (ler_numero(&opcao)) opcao = -1;

            switch(opcao)
            {
                case COMERCIANTE_QUER_COMPRAR:
                    if (jogador_obter_ouro(&jogo->jogador) >= COMERCIANTE_PRECO_BOTA)
                    {
                        if (!jogador_tem_bota(&jogo->jogador))
                        {
                            puts("Hehe, volte sempre!");
                            jogador_alterar_ouro(&jogo->jogador, jogador_obter_ouro(&jogo->jogador) - COMERCIANTE_PRECO_BOTA);
                            jogador_adicionar_bota(&jogo->jogador);
                        }
                        else
                        {
                            puts("Voce ja esta equipado com uma bota!");
                        }
                    }
                    else
                    {
                        puts("Sem dinherio, sem bota!");
                    }
                    break;

                case COMERCIANTE_NAO_QUER_COMPRAR:
                    puts("Que pena...");
                    break;

                default:
                    puts("Nao brinque comigo, quer saber? Vou embora que ganho mais!");
            }
            break;
    }
}

void jogo_encontrar_sacerdote(Jogo *jogo)
{
    if (jogador_obter_vida(&jogo->jogador) != jogador_obter_vida_max(&jogo->jogador))
    {
        puts("Sacerdote: vou curar suas feridas! Ate logo, bravo aventureiro!");
        jogador_alterar_vida(&jogo->jogador, jogador_obter_vida_max(&jogo->jogador));
    }
    else
    {
        puts("Sacerdote: cuidado com os monstros desse mundo!");
    }
}

void jogo_encontrar_inimigo(Jogo *jogo)
{
    if (JOGO_GERAR_INIMIGO)
    {
        inimigo_criar(
            &jogo->inimigo,
            "Goblin",
            GOBLIN_VIDA,
            GOBLIN_ATAQUE,
            GOBLIN_VELOCIDADE
        );
    }
    else
    {
        inimigo_criar(
            &jogo->inimigo,
            "Ogro",
            OGRO_VIDA,
            OGRO_ATAQUE,
            OGRO_VELOCIDADE
        );
    }

    jogo_balhar_imprimir_dados(jogo);
    pausar_tela("Pressione enter para batalhar...");
    puts("\n--------------------------------------------\n");
    jogo_balhar(jogo);

    inimigo_liberar(&jogo->inimigo);
}

void jogo_balhar(Jogo *jogo)
{
    while (1)
    {
        if (jogador_obter_velocidade(&jogo->jogador) > inimigo_obter_velocidade(&jogo->inimigo))
        {
            printf("Voce atacou o inimigo e causou %d de dano! \n", jogador_obter_ataque(&jogo->jogador));
            pausar_tela("Pressione enter para continuar...");
            puts("\n--------------------------------------------\n");

            inimigo_alterar_vida(&jogo->inimigo, inimigo_obter_vida(&jogo->inimigo) - jogador_obter_ataque(&jogo->jogador));
            jogo_balhar_imprimir_dados(jogo);
            pausar_tela("Pressione enter para continuar...");
            puts("\n--------------------------------------------\n");

            if (inimigo_obter_vida(&jogo->inimigo) <= 0)
            {
                puts("O inimigo morreu...");
                break;
            }

            printf("O inimigo atacou voce e causou %d de dano! \n", inimigo_obter_ataque(&jogo->inimigo));
            pausar_tela("Pressione enter para continuar...");
            puts("\n--------------------------------------------\n");

            jogador_alterar_vida(&jogo->jogador, jogador_obter_vida(&jogo->jogador) - inimigo_obter_ataque(&jogo->inimigo));
            jogo_balhar_imprimir_dados(jogo);
            pausar_tela("Pressione enter para continuar...");
            puts("\n--------------------------------------------\n");

            if (jogador_obter_vida(&jogo->jogador) <= 0)
            {
                puts("Voce morreu...");
                break;
            }
        }
        else
        {
            printf("O inimigo atacou voce e causou %d de dano! \n", inimigo_obter_ataque(&jogo->inimigo));
            pausar_tela("Pressione enter para continuar...");
            puts("\n--------------------------------------------\n");

            jogador_alterar_vida(&jogo->jogador, jogador_obter_vida(&jogo->jogador) - inimigo_obter_ataque(&jogo->inimigo));
            jogo_balhar_imprimir_dados(jogo);
            pausar_tela("Pressione enter para continuar...");
            puts("\n--------------------------------------------\n");

            if (jogador_obter_vida(&jogo->jogador) <= 0)
            {
                puts("Voce morreu...");
                break;
            }

            printf("Voce atacou o inimigo e causou %d de dano! \n", jogador_obter_ataque(&jogo->jogador));
            pausar_tela("Pressione enter para continuar...");
            puts("\n--------------------------------------------\n");

            inimigo_alterar_vida(&jogo->inimigo, inimigo_obter_vida(&jogo->inimigo) - jogador_obter_ataque(&jogo->jogador));
            jogo_balhar_imprimir_dados(jogo);
            pausar_tela("Pressione enter para continuar...");
            puts("\n--------------------------------------------\n");

            if (inimigo_obter_vida(&jogo->inimigo) <= 0)
            {
                puts("O inimigo morreu...");
                break;
            }
        }
    }
}

void jogo_balhar_imprimir_dados(Jogo *jogo)
{
    system(LIMPAR_TELA);
    puts("\n--------------------------------------------\n");

    printf("Nome: %s \n", jogador_obter_nome(&jogo->jogador));
    printf("Vida: %d / %d \n", jogador_obter_vida(&jogo->jogador), jogador_obter_vida_max(&jogo->jogador));

    puts("\n--------------------------------------------\n");

    printf("Nome: %s \n", inimigo_obter_nome(&jogo->inimigo));
    printf("Vida: %d / %d \n", inimigo_obter_vida(&jogo->inimigo), inimigo_obter_vida_max(&jogo->inimigo));

    puts("\n--------------------------------------------\n");
}