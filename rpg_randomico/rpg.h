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
//  Gerador de aventura
#define TERRENO_NUMERO rand() % 5
#define ENCONTRO_NUMERO rand() % 5
//  Rank
#define RANK_1 49
#define RANK_2 99
#define RANK_3 999
//  Arquivos
#define ARQUIVO_NOME "dados.txt"
#define ARQUIVO_LEITURA "r"
#define ARQUIVO_EDICAO "r+"

/*  Variaveis */

/*  Structs */
enum enum_menu
{
    sair_jogo,
    novo_jogo,
    rank
};

enum enum_terreno
{
    cidade,
    deserto,
    floresta,
    planice,
    masmorra
};

enum enum_encontro
{
    aldeao,
    comerciante,
    sacerdote,
    ladrao,
    ogro
};

/*  Funcoes */
int printar_menu(void);
int verificar_opcao(int opcao);
int rodar_jogo(void);
int gerador_aventura(int x, int y);
void printar_rank(void);
void salvar_rank(int rank);
int carregar_rank(void);
void remover_enter(char palavra[], int tamanho);

#endif // RPG_H_INCLUDED