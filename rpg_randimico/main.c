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
void gerador_aventura(void);
/*  Funcao que verifica qual foi o local e o acontecimento e os ativa de fato */
void verificar_aventura(int x, int y);
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
