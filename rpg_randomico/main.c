#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"

int main(void)
{
    int loop;

    do
    {
        /* Menu */
        system(LIMPAR_TELA);

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

    return 0;
}