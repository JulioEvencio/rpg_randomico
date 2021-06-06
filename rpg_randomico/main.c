#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"
#include "jogador/jogador.h"

int main(void)
{
    int loop;

    Jogador *player;

    if (jogador_criar(&player, "Teste 123"));

    do
    {
        /* Menu */
        system(LIMPAR_TELA);

        printf("%s \n", jogador_obter_nome(&player));
        printf("Opcao: ");
        if (ler_numero(&loop))
        {
            puts("Digite um numero!");
            pausar_tela("Pressione enter para continuar...");
            continue;
        }

        switch (loop)
        {
            case JOGAR:
                puts("Jogar...");
                break;

            case RANK:
                puts("Rank...");
                break;

            case SAIR:
                puts("Sair...");
                break;

            default:
                puts("Opcao invalida!");
        }

        pausar_tela("Pressione enter para continuar...");
    } while (loop);

    jogador_liberar(&player);

    return 0;
}