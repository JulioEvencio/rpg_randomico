#ifndef INIMIGO_H_INCLUDED
#define INIMIGO_H_INCLUDED

typedef struct Inimigo Inimigo;

int inimigo_criar(Inimigo **inimigo, char *nome, int vida, int ataque, int velocidade);
void inimigo_liberar(Inimigo **inimigo);

char *inimigo_obter_nome(Inimigo **inimigo);

int inimigo_obter_vida_max(Inimigo **inimigo);

int inimigo_obter_vida(Inimigo **inimigo);
void inimigo_alterar_vida(Inimigo **inimigo, int vida);

int inimigo_obter_ataque(Inimigo **inimigo);
int inimigo_obter_velocidade(Inimigo **inimigo);

#endif