#ifndef LUTA_H_INCLUDED
#define LUTA_H_INCLUDED

/*  Constantes */
#define PERSONAGEM_MORREU personagem.vida_atual <= 0
#define INIMIGO_MORREU inimigo[x].vida_atual <= 0

/*  Variaveis */

/*  Structs */

/*  Funcoes */
void iniciar_luta(int x);
void atacar_inimigo(int x);
void atacar_personagem(int x);
void controlar_dados(int x);

#endif // LUTA_H_INCLUDED