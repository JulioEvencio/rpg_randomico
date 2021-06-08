#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"
#include "menu/menu.h"
#include "jogo/jogo.h"

int main(void)
{
    int loop;

    Jogo *jogo;

    if (jogo_criar(&jogo))
    {
        puts("Erro ao criar o jogo!");
        return 1;
    }

    do
    {
        if (menu_imprimir(&loop)) loop = -1;

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

    jogo_liberar(&jogo);

    return 0;
}