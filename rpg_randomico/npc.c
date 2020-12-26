//  Bibliotecas
#include "rpg.h"

/*  Funcoes */
/*  Funcao do Aldeao */
void acao_aldeao(void)
{
    int x;
    x = ALDEAO_FRASES;
    printf("----------------------------------------- \n");
    printf("Aldeao: ");
    switch(x)
    {
        case(ALDEAO_FRASE_1):
            printf("Voce nao e bem vindo aqui \n");
            break;
        case(ALDEAO_FRASE_2):
            printf("Seu fim esta proximo... \n");
            break;
        case(ALDEAO_FRASE_3):
            printf("Um heroi! isso que este mundo precisa... \n");
            break;
        default:
            printf("Esqueci o que ia falar... \n");
            break;
    }
    printf("----------------------------------------- \n");
}