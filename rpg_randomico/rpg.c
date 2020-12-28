//  Bibliotecas
#include "rpg.h"

/*  Funcoes */
//  Funcao que printa o menu  e logo em seguida retorna a opcao desejada do usuario
int printar_menu(void)
{
    int opcao;
    printf("------MENU------ \n");
    printf("1. Novo jogo \n");
    printf("2. Rank \n");
    printf("0. Sair do jogo \n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    setbuf(stdin, NULL);
    return opcao;
}