#ifndef MONSTROS_H_INCLUDED
#define MONSTROS_H_INCLUDED

/*  Constantes */
//  Constantes gerias
#define INIMIGO_NOME 50
#define INIMIGO_QUANTIDADE 2
//  Ladrao
#define LADRAO_ATAQUE
#define LADRAo_VIDA
#define LADRAO_VELOCIDADE
//  Ogro
#define OGRO_ATAQUE
#define OGRO_VIDA
#define OGRO_VELOCIDADE

/*  Variaveis */

/*  Structs */
struct tipo_inimigo
{
    char nome[INIMIGO_NOME];
    int ataque;
    int vida_atual;
    int vida_maxima;
    int velocidade;
};
typedef struct tipo_inimigo Inimigo[INIMIGO_QUANTIDADE];

/*  Funcoes */

#endif // MONSTROS_H_INCLUDED