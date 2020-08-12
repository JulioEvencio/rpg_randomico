/*  Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

/*  Funcao main */
int main()
{
    /*  */

    return 0;
}

/*  Funcao do NPC */
void acao_npc(void)
{
    int x;
    x = rand() % 2;
    printf("----------------------------------------- \n");
    printf("Aldeao: ");
    switch(x)
    {
        case(0):
            printf("Voce nao e bem vindo aqui \n");
            break;
        case(1):
            printf("Seu fim esta proximo... \n");
            break;
        case(2):
            printf("Um heroi, isso que este mundo precisa... \n");
            break;
    }
    printf("----------------------------------------- \n");
    system("pause");
}
