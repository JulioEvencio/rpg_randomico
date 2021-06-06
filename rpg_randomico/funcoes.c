#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"

void pausar_tela(char *mensagem)
{
    char letra;

    printf("%s", mensagem);

    while ((letra = getchar()) != '\n');
}

int ler_numero(int *numero)
{
    enum {BUFFER_TAMANHO = 10};
    char buffer[BUFFER_TAMANHO];
    int tem_letra = 0;

    ler_string(buffer, BUFFER_TAMANHO);

    if (buffer[0] == '\0') return LER_ERRO;

    for (int i = 0; i < BUFFER_TAMANHO; i++)
    {
        if (buffer[i] == '\0') break;

        if (buffer[i] < '0' || buffer[i] > '9') return LER_TEM_LETRA;
    }

    *numero = atoi(buffer);

    return LER_SUCESSO;
}

void ler_string(char *string, int tamanho)
{
    int i = 0;
    char letra;

    while ((letra = getchar()) != '\n')
    {
        if (letra != '\n' && i < tamanho - 1)
        {
            *(string + i) = letra;
            i++;
        }
    }

    *(string + i) = '\0';
}