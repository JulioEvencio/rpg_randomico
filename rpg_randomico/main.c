#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cabecalho.h"
#include "menu/menu.h"
#include "jogo/jogo.h"
#include "rank/rank.h"

int main(void)
{
    int loop;

    srand(time(NULL));

    do
    {
        if (menu_imprimir(&loop)) loop = -1;

        switch (loop)
        {
            case JOGAR:
                if (jogo_jogar()) puts("Erro ao iniciar o jogo!");
                break;

            case RANK:
                if (rank_imprimir()) puts("Erro ao imprimir rank!");
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