/*  Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*  Struct dos monstros */
typedef struct Lista_monstros
{
    char nome[100];
    int ataque;
    int vida;
    int velocidade;
}Base_monstros;
Base_monstros monstros[2];

/*  Lista de monstros */
/*  Ladrao */
strcpy(monstros[0].nome, "Ladrao");
monstros[0].ataque = 3;
monstros[0].vida = 3;
monstros[0].velocidade = 3;
/*  Ogro */
strcpy(monstros[1].nome, "Ogro");
monstros[1].ataque = 2;
monstros[1].vida = 5;
monstros[1].velocidade = 1;

/*  Funcoes */
/*  Funcao que printa o menu  e logo em seguida retorna a opcao desejada do usuario */
int printar_menu(void);
/*  Funcao que recebe e verifica a opcao do usuario e a ativa */
int verificar_opcao(int opcao);
/*  Funcao que o jogo em si vai rodar */
int rodar_jogo(void);
/* Funcao que decide a aventura de cada turno, isto e, o local e oq ocorre la. Depois de gerar ele retorna os valores */
int gerador_aventura(int x, int y);
/*  Funcao do NPC */
void acao_npc(void);
/*  Funcao do comerciante */
void acao_comerciante(void);
/*  Funcao do padre */
void acao_padre(void);
/*  Funcao do ladrao */
void acao_ladrao(void);
/*  Funcao do ogro */
void acao_ogro(void);
/*  Funcao que reseta o personagem */
void resetar_personagem(void);
/*  Funcao que aumenta os atributos dos personagem de acordo com seu level */
void aumentar_atributos(void);
/*  Funcao responsavel pelo sistema de luta do jogo */
void inicar_luta(void);

/*  Funcao main */
int main()
{
    /*  */

    return 0;
}

/*  Funcao que printa o menu  e logo em seguida retorna a opcao desejada do usuario */
int printar_menu(void)
{
    int opcao;
    printf("------MENU------ \n");
    printf("1. Novo jogo \n");
    printf("2. Rank \n");
    printf("3. Sair do jogo \n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    setbuf(stdin, NULL);
    return opcao;
}

/*  Funcao que recebe e verifica a opcao do usuario e a ativa */
int verificar_opcao(int opcao)
{
    switch(opcao)
    {
        case(1):
            rodar_jogo();
            return 0;
            break;
        case(2):
            printf("Em desenvolvimento \n");
            return 0;
            break;
        case(0):
            printf("Obrigado por jogar! \n");
            return -1;
            break;
        default:
            printf("Opcao invalida! \n");
            return 0;
    }
}

/* Funcao que decide a aventura de cada turno, isto e, o local e oq ocorre la. Depois de gerar ele retorna os valores */
int gerador_aventura(int x, int y)
{
    system("cls");
    /*  Texto do terreno */
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
            printf("uma Planice ");
            break;
        case(4):
            printf("uma masmorra ");
            break;
    }
    /*  Transicao do terreno para oq o jogador encontra */
    printf("e encontrou ");
    switch(y)
    {
        case(0):
            printf("um aldeao \n");
            acao_npc();
            break;
        case(1):
            printf("um comerciante \n");
            acao_comerciante();
            break;
        case(2):
            printf("um padre \n");
            acao_padre();
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
    /*  Verificando se o personagem esta vivo */
    if(x <= 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

/*  Funcao que o jogo em si vai rodar */
int rodar_jogo(void)
{
    int loop;
    do
    {
        system("cls");
        loop = gerador_aventura(rand() % 4, rand() % 4);
        system("pause");
    }while(loop != -1);
    return -1;
}
