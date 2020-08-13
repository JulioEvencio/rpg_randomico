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

/*  Funcao do comerciante */
void acao_comerciante(void)
{
    int x, op;
    x = rand() % 2;
    printf("----------------------------------------- \n");
    printf("Comerciante: Bem vindo aventureiro! \n");
    printf("Gostaria de comprar ");
    switch(x)
    {
        case(0):
            printf("uma espada por 100 moedas de ouro? \n");
            printf("1. Sim \n");
            printf("2. Nao \n");
            scanf("%d", &op);
            setbuf(stdin, NULL);
            switch(op)
            {
                case(1):
                    if(personagem.ouro >= 100)
                    {
                        printf("Hehe, volte sempre! \n");
                        personagem.ouro = personagem.ouro - 100;
                    }
                    else
                    {
                        printf("Sem dinherio, sem arma! \n");
                    }
                    break;
                case(2):
                    printf("Que pena... \n");
                    break;
                default:
                    printf("Nao brinque comigo, quer saber? Vou embora que ganho mais! \n");
            }
            break;
        case(1):
            printf("uma armadura por 80 moedas de ouro? \n");
            printf("1. Sim \n");
            printf("2. Nao \n");
            scanf("%d", &op);
            setbuf(stdin, NULL);
            switch(op)
            {
                case(1):
                    if(personagem.ouro >= 100)
                    {
                        printf("Haha, nos vemos em breve! \n");
                        personagem.ouro = personagem.ouro - 100;
                    }
                    else
                    {
                        printf("Voce nao tem ouro suficiente! \n");
                    }
                    break;
                case(2):
                    printf("Ok entao, nos vemos em breve! \n");
                    break;
                default:
                    printf("Nao brinque comigo, quer saber? Vou embora rapa! \n");
                    
            }
            break;
    }
}
