//  Bibliotecas
#include "rpg.h"

/*  Funcoes */
//  Funcao que reseta o personagem
void resetar_personagem(void)
{
    personagem.dia = PERSONAGEM_DIA;
    personagem.ouro = PERSONAGEM_OURO;
    personagem.ataque = PERSONAGEM_ATAQUE;
    personagem.vida_maxima = PERSONAGEM_VIDA;
    personagem.vida_atual = personagem.vida_maxima;
    personagem.velocidade = PERSONAGEM_VELOCIDADE;
    personagem.arma = PERSONAGEM_ARMA;
    personagem.armadura = PERSONAGEM_ARMADURA;
    personagem.amuleto = PERSONAGEM_AMULETO;
}

//  Funcao que adiciona ouro ao personagem
void adicionar_ouro(void)
{
    int x;
    x = OURO_VALOR;
    personagem.ouro = personagem.ouro + x;
    printf("Voce ganhou %d moedas de ouro! \n", x);
}

//  Funcao que printa as estatisticas do usuario
void printar_estatisticas(void)
{
    printf("Nome:   %s", personagem.nome);
    printf("Dia:    %d \n", personagem.dia);
    printf("Ouro:   %d \n", personagem.ouro);
    printf("Vida: %3d / %3d \n", personagem.vida_atual, personagem.vida_maxima);
}