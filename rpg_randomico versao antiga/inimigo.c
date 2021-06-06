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

/*  Funcao que gera os inimigos */
void gerar_inimigos(void)
{
    /*  Lista de monstros */
    /*  Ladrao */
    strcpy(inimigo[LADRAO_ID].nome, LADRAO_NOME);
    inimigo[LADRAO_ID].ataque = LADRAO_ATAQUE;
    inimigo[LADRAO_ID].vida_maxima = LADRAo_VIDA;
    inimigo[LADRAO_ID].vida_atual = inimigo[LADRAO_ID].vida_maxima;
    inimigo[LADRAO_ID].velocidade = LADRAO_VELOCIDADE;
    /*  Ogro */
    strcpy(inimigo[OGRO_ID].nome, OGRO_NOME);
    inimigo[OGRO_ID].ataque = OGRO_ATAQUE;
    inimigo[OGRO_ID].vida_maxima = OGRO_VIDA;
    inimigo[OGRO_ID].vida_atual = inimigo[OGRO_ID].vida_maxima;
    inimigo[OGRO_ID].velocidade = OGRO_VELOCIDADE;
}