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
        case(0):
            printf("Voce nao e bem vindo aqui \n");
            break;
        case(1):
            printf("Seu fim esta proximo... \n");
            break;
        case(2):
            printf("Um heroi! isso que este mundo precisa... \n");
            break;
    }
    printf("----------------------------------------- \n");
}