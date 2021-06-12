#include <stdio.h>
#include <stdlib.h>
#include "rank.h"
#include "../cabecalho.h"
#include "../jogador/jogador.h"

int rank_imprimir(void)
{
    int dias;
    char nome[JOGADOR_NOME];

    FILE *file = fopen(JOGO_ARQUIVO, JOGO_ARQUIVO_MODO_LEITURA);

    if (file == NULL) return -1;

    fscanf(file, "%[^;] %*c", nome);
    fscanf(file, "%d", &dias);

    fclose(file);

    system(LIMPAR_TELA);
    puts("----------------- Rank -----------------");
    printf("Nome: %s \n", nome);
    printf("Dias: %d \n", dias);
    puts("----------------------------------------");

    return 0;
}