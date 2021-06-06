#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

typedef struct Npc Npc;

int npc_criar(Npc **npc);
void npc_liberar(Npc **npc);

char *npc_obter_frase(Npc **npc, int frase);

#endif