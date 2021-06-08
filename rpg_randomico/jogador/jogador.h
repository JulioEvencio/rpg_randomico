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
void jogador_alterar_nome(Jogador **jogador, char *nome);

int jogador_obter_ouro(Jogador **jogador);
void jogador_alterar_ouro(Jogador **jogador, int ouro);

int jogador_obter_vida_max(Jogador **jogador);
void jogador_alterar_vida_max(Jogador **jogador, int vida_max);

int jogador_obter_vida(Jogador **jogador);
void jogador_alterar_vida(Jogador **jogador, int vida);

int jogador_obter_ataque(Jogador **jogador);
void jogador_alterar_ataque(Jogador **jogador, int ataque);

int jogador_obter_velocidade(Jogador **jogador);
void jogador_alterar_velocidade(Jogador **jogador, int velocidade);

int jogador_tem_arma(Jogador **jogador);
void jogador_adicionar_arma(Jogador **jogador);

int jogador_tem_armadura(Jogador **jogador);
void jogador_adicionar_armadura(Jogador **jogador);

int jogador_tem_bota(Jogador **jogador);
void jogador_adicionar_bota(Jogador **jogador);

#endif