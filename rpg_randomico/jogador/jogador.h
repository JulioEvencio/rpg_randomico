#ifndef JOGADOR_H_INCLUDED
#define JOGADOR_H_INCLUDED

enum
{
    JOGADOR_NOME = 31
};

typedef struct Jogador Jogador;

int jogador_criar(Jogador **jogador, char *nome);
void jogador_liberar(Jogador **jogador);

char *jogador_obter_nome(Jogador **jogador);

int jogador_obter_ouro(Jogador **jogador);
void jogador_alterar_ouro(Jogador **jogador, int ouro);

int jogador_obter_vida(Jogador **jogador);
int jogador_obter_ataque(Jogador **jogador);
int jogador_obter_velocidade(Jogador **jogador);

int jogador_tem_arma(Jogador **jogador);
void jogador_adicionar_arma(Jogador **jogador);

int jogador_tem_armadura(Jogador **jogador);
void jogador_adicionar_armadura(Jogador **jogador);

int jogador_tem_bota(Jogador **jogador);
void jogador_adicionar_bota(Jogador **jogador);

#endif