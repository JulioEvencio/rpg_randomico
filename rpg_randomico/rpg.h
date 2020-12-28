#ifndef RPG_H_INCLUDED
#define RPG_H_INCLUDED

//  Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "personagem.h"
#include "inimigo.h"
#include "npc.h"
#include "luta.h"

/*  Constantes */

/*  Variaveis */

/*  Structs */

/*  Funcoes */
int printar_menu(void);
int verificar_opcao(int opcao);
int rodar_jogo(void);
int gerador_aventura(int x, int y);

#endif // RPG_H_INCLUDED