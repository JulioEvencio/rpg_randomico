#ifndef PERSONAGEM_H_INCLUDED
#define PERSONAGEM_H_INCLUDED

/*  Constantes */
#define PERSONAGEM_NOME 50

/*  Variaveis */

/*  Structs */
struct tipo_personagem
{
    char nome[PERSONAGEM_NOME];
    int dia;
    int rank;
    int ouro;
    int ataque;
    int vida_maxima;
    int vida_atual;
    int velocidade;
    int arma;
    int armadura;
    int amuleto;
};
typedef struct tipo_personagem Personagem;
Personagem personagem;

/*  Funcoes */

#endif // PERSONAGEM_H_INCLUDED