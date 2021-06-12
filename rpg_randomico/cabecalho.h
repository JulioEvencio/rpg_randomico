#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLDUED

#define LIMPAR_TELA "clear || cls"
#define JOGO_ARQUIVO "dados/dados.txt"
#define JOGO_ARQUIVO_MODO_ESCRITA "w"
#define JOGO_ARQUIVO_MODO_LEITURA "r"

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