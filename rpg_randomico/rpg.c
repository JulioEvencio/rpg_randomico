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

//  Funcao que recebe e verifica a opcao do usuario e a ativa
int verificar_opcao(int opcao)
{
    switch(opcao)
    {
        case(1):
            rodar_jogo();
            return 0;
            break;
        case(2):
            printar_rank();
            return 0;
            break;
        case(0):
            printf("Obrigado por jogar! \n");
            printf("Pressione enter para continuar... \n");
            getchar();
            return -1;
            break;
        default:
            printf("Opcao invalida! \n");
            printf("Pressione enter para continuar... \n");
            getchar();
            return 0;
    }
}

//  Funcao que o jogo em si vai rodar
int rodar_jogo(void)
{
    int loop;
    resetar_personagem();
    gerar_inimigos();
    do
    {
        system("clear");
        printar_estatisticas();
        loop = gerador_aventura(rand() % 5, rand() % 5);
        printf("Pressione enter para continuar... \n");
        getchar();
        personagem.dia++;
    }while(loop != -1);
    return -1;
}