#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

/*  Constantes */
//  Aldeao
#define ALDEAO_FRASES rand() % 3
#define ALDEAO_FRASE_1 0
#define ALDEAO_FRASE_2 1
#define ALDEAO_FRASE_3 3
//  Axiliares
#define QUER_COMPRAR 1
#define NAO_QUER_COMPRAR 2
//  Comerciante
#define COMERCIANTE_VENDAS rand() % 3
#define COMERCIANTE_ARMA 0
#define COMERCIANTE_ARMADURA 1
#define COMERCIANTE_AMULETO 2
//  Itens
//  Espada
#define ESPADA_PRECO 100
#define ESPADA_ATAQUE 1
#define ESPADA_BLOQUEADA 0
//  Armadura
#define ARMADURA_PRECO 80
#define ARMADURA_PROTECAO 5
#define ARMADURA_BLOQUEADA 0
//  Amuleto
#define AMULETO_PRECO 50
#define AMULETO_VELOCIDADE 3
#define AMULETO_BLOQUEADO 0

/*  Variaveis */

/*  Structs */

/*  Funcoes */
//  Funcao do Aldeao
void acao_aldeao(void);
//  Funcao do comerciante
void acao_comerciante(void);
//  Funcao do padre
void acao_sacerdote(void);

#endif // NPC_H_INCLUDED