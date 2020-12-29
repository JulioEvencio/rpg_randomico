//  Bibliotecas
#include "rpg.h"

/*  Funcoes */
//  Funcao que printa o menu  e logo em seguida retorna a opcao desejada do usuario
int printar_menu(void)
{
    int opcao;
    printf("------MENU------ \n");
    printf("1. Novo jogo \n");
    printf("2. Rank \n");
    printf("0. Sair do jogo \n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    setbuf(stdin, NULL);
    return opcao;
}

//  Funcao que recebe e verifica a opcao do usuario e a ativa
int verificar_opcao(int opcao)
{
    switch(opcao)
    {
        case(novo_jogo):
            rodar_jogo();
            return 0;
            break;
        case(rank):
            printar_rank();
            return 0;
            break;
        case(sair_jogo):
            printf("Obrigado por jogar! \n");
            printf("Pressione enter para continuar... \n");
            getchar();
            setbuf(stdin, NULL);
            return -1;
            break;
        default:
            printf("Opcao invalida! \n");
            printf("Pressione enter para continuar... \n");
            getchar();
            setbuf(stdin, NULL);
            return 0;
    }
}

//  Funcao que o jogo em si vai rodar
int rodar_jogo(void)
{
    int loop;
    resetar_personagem();
    gerar_inimigos();
    do
    {
        system("clear");
        printar_estatisticas();
        loop = gerador_aventura(TERRENO_NUMERO, ENCONTRO_NUMERO);
        printf("Pressione enter para continuar... \n");
        getchar();
        setbuf(stdin, NULL);
        personagem.dia++;
    }while(loop != -1);
    return -1;
}

// Funcao que decide a aventura de cada turno, isto e, o local e o que ocorre la. Depois de gerar ele retorna os valores
int gerador_aventura(int x, int y)
{
    //  Texto do terreno
    printf("Voce chegou a ");
    switch(x)
    {
        case(cidade):
            printf("uma cidade ");
            break;
        case(deserto):
            printf("um deserto ");
            break;
        case(floresta):
            printf("uma floresta ");
            break;
        case(planice):
            printf("uma planice ");
            break;
        case(masmorra):
            printf("uma masmorra ");
            break;
    }
    //  Transicao do terreno para o que o jogador encontra
    printf("e encontrou ");
    switch(y)
    {
        case(aldeao):
            printf("um aldeao \n");
            acao_aldeao();
            break;
        case(comerciante):
            printf("um comerciante \n");
            acao_comerciante();
            break;
        case(sacerdote):
            printf("um sarcedote \n");
            acao_sacerdote();
            break;
        case(ladrao):
            printf("um ladrao \n");
            acao_ladrao();
            break;
        case(ogro):
            printf("um ogro \n");
            acao_ogro();
            break;
    }
    //  Verificando se o personagem esta vivo
    if(personagem.vida_atual <= 0)
    {
        //  Verificando se o usuario quebrou o recorde de dias sobrevividos e depois salvando
        if(personagem.rank < personagem.dia)
        {
            personagem.rank = personagem.dia;
            salvar_rank(personagem.rank);
        }
        return -1;
    }
    else
    {
        return 0;
    }
}

//  Funcao que printa o rank maximo alcancado pelo usuario
void printar_rank(void)
{
    system("clear");
    if(personagem.rank >= RANK_3)
    {
        printf("Seu recorde e de %d dias sobrevividos! \n", personagem.rank);
        printf("Reza a lenda que um heroi nasceria na humanidade... E parece que e voce! \n");
    }
    else
    {
        if(personagem.rank > RANK_2)
        {
            printf("Seu recorde e de %d dias sobrevividos! \n", personagem.rank);
            printf("Voce e um jogador muito empenhado! \n");
        }
        else
        {
            if(personagem.rank > RANK_1)
            {
                printf("Seu recorde e de %d dias sobrevividos! Continue assim! \n", personagem.rank);
            }
            else
            {
                printf("Seu recorde e de %d dias sobrevividos... \n", personagem.rank);
                printf("Voce nao e grande coisa... \n");
            }
            
        }
        
    }
    
    printf("Pressione enter para voltar ao menu... \n");
    getchar();
    setbuf(stdin, NULL);
}

//  Funcao que salva o rank maximo em um arquivo .txt
void salvar_rank(int rank)
{
    FILE *file;

    file = fopen(ARQUIVO_NOME, ARQUIVO_EDICAO);

    fprintf(file, "%d", rank);

    fclose(file);
}

//  Funcao que carrega o rank maximo do usuario
int carregar_rank(void)
{
    int rank;
    FILE *file;

    file = fopen(ARQUIVO_NOME, ARQUIVO_LEITURA);

    fscanf(file, "%d", &rank);

    fclose(file);

    return rank;
}

//  Funcao que remove o 'ENTER' das palavras
void remover_enter(char palavra[], int tamanho)
{
    for(int incremento = 0; incremento < tamanho; incremento++)
    {
        if(palavra[incremento] == '\n')
        {
            palavra[incremento] = '\0';
        }
    }
}