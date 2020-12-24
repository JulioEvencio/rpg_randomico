#ifndef PERSONAGEM_H_INCLUDED
#define PERSONAGEM_H_INCLUDED

/*  Constantes */
//  Personagem
#define PERSONAGEM_NOME 50
#define PERSONAGEM_DIA 1
#define PERSONAGEM_OURO 1
#define PERSONAGEM_ATAQUE 5
#define PERSONAGEM_VIDA 20
#define PERSONAGEM_VELOCIDADE 3
#define PERSONAGEM_ARMA 0
#define PERSONAGEM_ARMADURA 0
#define PERSONAGEM_AMULETO 0
//  Ouro
#define OURO_VALOR (rand() % 6) + 1

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
void resetar_personagem(void);
void adicionar_ouro(void);

#endif // PERSONAGEM_H_INCLUDED