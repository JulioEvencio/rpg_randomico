//  Bibliotecas
#include "rpg.h"
#include "rpg.c"
#include "personagem.c"
#include "npc.c"
#include "inimigo.c"
#include "luta.c"

/*  Funcoes */
/*  Funcao que recebe e verifica a opcao do usuario e a ativa */
int verificar_opcao(int opcao);
/*  Funcao que o jogo em si vai rodar */
int rodar_jogo(void);
/* Funcao que decide a aventura de cada turno, isto e, o local e oq ocorre la. Depois de gerar ele retorna os valores */
int gerador_aventura(int x, int y);
/*  Funcao que printa o rank maximo alcancado pelo usuario */
void printar_rank(void);
/*  Funcao que salva o rank maximo em um arquivo .txt */
void salvar_rank(int rank);
/*  Funcao que carrega o rank maximo do usuario */
int carregar_rank(void);

/*  Funcao main */
int main()
{
    /*  Variaveis */
    int loop;
    /*  Criando semente para a funcao rand */
    srand(time(NULL));
    /*  Limpamdo tela antes de iniciar */
    system("clear");
    /*  Registro do usuario */
    printf("Bem vindo ao RPG Randomico! \n");
    printf("Qual e seu nome de aventureiro? \n");
    printf("Nome: ");
    fgets(personagem.nome, 100, stdin);
    setbuf(stdin, NULL);
    /*  Carregando o rank maximo do usuario */
    personagem.rank = carregar_rank();
    /*  Loop do menu do jogo */
    do
    {
        system("clear");
        loop = verificar_opcao(printar_menu());
    } while (loop != -1);
    

    return 0;
}

/*  Funcao que recebe e verifica a opcao do usuario e a ativa */
int verificar_opcao(int opcao)
{
    switch(opcao)
    {
        case(1):
            rodar_jogo();
            return 0;
            break;
        case(2):
            printar_rank();
            return 0;
            break;
        case(0):
            printf("Obrigado por jogar! \n");
            printf("Pressione enter para continuar... \n");
            getchar();
            return -1;
            break;
        default:
            printf("Opcao invalida! \n");
            printf("Pressione enter para continuar... \n");
            getchar();
            return 0;
    }
}

/* Funcao que decide a aventura de cada turno, isto e, o local e o que ocorre la. Depois de gerar ele retorna os valores */
int gerador_aventura(int x, int y)
{
    /*  Texto do terreno */
    printf("Voce chegou a ");
    switch(x)
    {
        case(0):
            printf("uma cidade ");
            break;
        case(1):
            printf("um deserto ");
            break;
        case(2):
            printf("uma floresta ");
            break;
        case(3):
            printf("uma planice ");
            break;
        case(4):
            printf("uma masmorra ");
            break;
    }
    /*  Transicao do terreno para o que o jogador encontra */
    printf("e encontrou ");
    switch(y)
    {
        case(0):
            printf("um aldeao \n");
            acao_aldeao();
            break;
        case(1):
            printf("um comerciante \n");
            acao_comerciante();
            break;
        case(2):
            printf("um sarcedote \n");
            acao_sacerdote();
            break;
        case(3):
            printf("um ladrao \n");
            acao_ladrao();
            break;
        case(4):
            printf("um ogro \n");
            acao_ogro();
            break;
    }
    /*  Verificando se o personagem esta vivo */
    if(personagem.vida_atual <= 0)
    {
        /*  Verificando se o usuario quebrou o recorde de dias sobrevividos e depois salvando */
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

/*  Funcao que o jogo em si vai rodar */
int rodar_jogo(void)
{
    int loop;
    resetar_personagem();
    gerar_inimigos();
    do
    {
        system("clear");
        printar_estatisticas();
        loop = gerador_aventura(rand() % 5, rand() % 5);
        printf("Pressione enter para continuar... \n");
        getchar();
        personagem.dia++;
    }while(loop != -1);
    return -1;
}

/*  Funcao que printa o rank maximo alcancado pelo usuario */
void printar_rank(void)
{
    system("clear");
    if(personagem.rank >= 999)
    {
        printf("Seu recorde e de %d dias sobrevividos! \n", personagem.rank);
        printf("Reza a lenda que um heroi nasceria na humanidade... E parece que e voce! \n");
    }
    else
    {
        if(personagem.rank > 99)
        {
            printf("Seu recorde e de %d dias sobrevividos! \n", personagem.rank);
            printf("Voce e um jogador muito empenhado! \n");
        }
        else
        {
            if(personagem.rank > 49)
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
}

/*  Funcao que salva o rank maximo em um arquivo .txt */
void salvar_rank(int rank)
{
    FILE *file;

    file = fopen("dados.txt", "r+");

    fprintf(file, "%d", rank);

    fclose(file);
}

/*  Funcao que carrega o rank maximo do usuario */
int carregar_rank(void)
{
    int rank;
    FILE *file;

    file = fopen("dados.txt", "r");

    fscanf(file, "%d", &rank);

    fclose(file);

    return rank;
}