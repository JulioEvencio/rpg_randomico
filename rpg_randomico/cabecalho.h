#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLDUED

#define LIMPAR_TELA "clear || cls"

enum
{
    LER_SUCESSO,
    LER_ERRO,
    LER_TEM_LETRA
};

enum
{
    SAIR,
    JOGAR,
    RANK
};

void pausar_tela(char *mensagem);
int ler_numero(int *numero);
void ler_string(char *string, int tamanho);

#endif