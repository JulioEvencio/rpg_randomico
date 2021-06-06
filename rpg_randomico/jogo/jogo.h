#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

typedef struct Jogo Jogo;

int jogo_criar(Jogo **jogo);
void jogo_liberar(Jogo **jogo);

#endif