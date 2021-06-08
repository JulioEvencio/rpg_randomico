#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"
#include "menu/menu.h"
#include "jogo/jogo.h"

int main(void)
{
    int loop;

    do
    {
        if (menu_imprimir(&loop)) loop = -1;

        switch (loop)
        {
            case JOGAR:
                if (jogo_jogar()) puts("Erro ao iniciar o jogo!");
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