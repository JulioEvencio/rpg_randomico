#ifndef MONSTROS_H_INCLUDED
#define MONSTROS_H_INCLUDED

/*  Constantes */
//  Constantes gerias
#define INIMIGO_NOME 50
#define INIMIGO_QUANTIDADE 2
//  Ladrao
#define LADRAO_ID 0
#define LADRAO_ATAQUE
#define LADRAo_VIDA
#define LADRAO_VELOCIDADE
//  Ogro
#define OGRO_ID 1
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
typedef struct tipo_inimigo Inimigo;
Inimigo inimigo[INIMIGO_QUANTIDADE];

/*  Funcoes */
void acao_ladrao(void);
void acao_ogro(void);
void criar_inimigos(void);
void gerar_inimigos(void);

#endif // MONSTROS_H_INCLUDED