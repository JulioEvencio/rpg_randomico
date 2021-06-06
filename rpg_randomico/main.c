#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"
#include "menu/menu.h"
#include "jogador/jogador.h"

int main(void)
{
    int loop;

    do
    {
        if (menu_imprimir(&loop))
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
                puts("Obrigado por utilizar este programa!");
                break;

            default:
                puts("Opcao invalida!");
        }

        pausar_tela("Pressione enter para continuar...");
    } while (loop);

    return 0;
}