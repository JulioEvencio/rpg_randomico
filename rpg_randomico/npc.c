//  Bibliotecas
#include "rpg.h"

/*  Funcoes */
/*  Funcao do padre */
void acao_sacerdote(void)
{
    printf("----------------------------------------- \n");
    printf(SARCEDOTE_NOME);
    if(personagem.vida_atual != personagem.vida_maxima)
    {
        printf("Vou curar suas feridas! Ate logo bravo aventureiro! \n");
        personagem.vida_atual = personagem.vida_maxima;
    }
    else
    {
        printf("Cuidado com os monstros desse mundo! \n");
    }
    printf("----------------------------------------- \n");
    
}