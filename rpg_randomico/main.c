//  Bibliotecas
#include "rpg.h"
#include "rpg.c"
#include "personagem.c"
#include "npc.c"
#include "inimigo.c"
#include "luta.c"

/*  Funcoes */
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