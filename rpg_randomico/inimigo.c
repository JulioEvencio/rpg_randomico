#include "rpg.h"

/*  Funcoes */
/*  Funcao do ladrao */
void acao_ladrao(void)
{
    iniciar_luta(LADRAO_ID);
}

/*  Funcao do ogro */
void acao_ogro(void)
{
    iniciar_luta(OGRO_ID);
}