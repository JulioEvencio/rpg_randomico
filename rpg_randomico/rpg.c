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

// Funcao que decide a aventura de cada turno, isto e, o local e o que ocorre la. Depois de gerar ele retorna os valores
int gerador_aventura(int x, int y)
{
    //  Texto do terreno
    printf("Voce chegou a ");
    switch(x)
    {
        case(0):
            printf("uma cidade ");
            break;
        case(1):
            printf("um deserto ");
            break;
        case(2):
            printf("uma floresta ");
            break;
        case(3):
            printf("uma planice ");
            break;
        case(4):
            printf("uma masmorra ");
            break;
    }
    //  Transicao do terreno para o que o jogador encontra
    printf("e encontrou ");
    switch(y)
    {
        case(0):
            printf("um aldeao \n");
            acao_aldeao();
            break;
        case(1):
            printf("um comerciante \n");
            acao_comerciante();
            break;
        case(2):
            printf("um sarcedote \n");
            acao_sacerdote();
            break;
        case(3):
            printf("um ladrao \n");
            acao_ladrao();
            break;
        case(4):
            printf("um ogro \n");
            acao_ogro();
            break;
    }
    //  Verificando se o personagem esta vivo
    if(personagem.vida_atual <= 0)
    {
        //  Verificando se o usuario quebrou o recorde de dias sobrevividos e depois salvando
        if(personagem.rank < personagem.dia)
        {
            personagem.rank = personagem.dia;
            salvar_rank(personagem.rank);
        }
        return -1;
    }
    else
    {
        return 0;
    }
}