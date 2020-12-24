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