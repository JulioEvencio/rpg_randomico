#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "../cabecalho.h"

int menu_imprimir(int *opcao)
{
    system(LIMPAR_TELA);

    puts("----------------- Menu -----------------");
    puts("1. Jogar");
    puts("2. Rank");
    puts("0. Sair");
    printf("Opcao: ");

    if (ler_numero(opcao)) return -1;

    return 0;
}