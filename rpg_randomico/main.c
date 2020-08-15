/*  Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*  Struct dos monstros */
typedef struct Lista_monstros
{
    char nome[100];
    int ataque;
    int vida_maxima;
    int vida_atual;
    int velocidade;
}Base_monstros;
Base_monstros monstros[2];

/*  Struct de atributos do usuario */
typedef struct Atributos
{
    char nome[100];
    int level;
    int xp;
    int ouro;
    int ataque;
    int vida_maxima;
    int vida_atual;
    int velocidade;
    int arma;
    int armadura;
    int amuleto;
}Atributos_base;
Atributos_base personagem;

/*  Funcoes */
/*  Funcao que printa o menu  e logo em seguida retorna a opcao desejada do usuario */
int printar_menu(void);
/*  Funcao que recebe e verifica a opcao do usuario e a ativa */
int verificar_opcao(int opcao);
/*  Funcao que o jogo em si vai rodar */
int rodar_jogo(void);
/* Funcao que decide a aventura de cada turno, isto e, o local e oq ocorre la. Depois de gerar ele retorna os valores */
int gerador_aventura(int x, int y);
/*  Funcao do NPC */
void acao_npc(void);
/*  Funcao do comerciante */
void acao_comerciante(void);
/*  Funcao do padre */
void acao_padre(void);
/*  Funcao do ladrao */
void acao_ladrao(void);
/*  Funcao do ogro */
void acao_ogro(void);
/*  Funcao que reseta o personagem */
void resetar_personagem(void);
/*  Funcao que aumenta os atributos dos personagem de acordo com seu level */
void aumentar_atributos(void);
/*  Funcao responsavel pelo sistema de luta do jogo */
void inicar_luta(void);
/*  Funcao que gera os inimigos */
void gerar_inimigos(void);

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
    /*  Loop do menu do jogo */
    do
    {
        system("clear");
        loop = verificar_opcao(printar_menu());
        printf("Pressione qualquer tecla para continuar... \n");
        getchar();
    } while (loop != -1);
    

    return 0;
}

/*  Funcao que printa o menu  e logo em seguida retorna a opcao desejada do usuario */
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
            printf("Em desenvolvimento \n");
            return 0;
            break;
        case(0):
            printf("Obrigado por jogar! \n");
            return -1;
            break;
        default:
            printf("Opcao invalida! \n");
            return 0;
    }
}

/* Funcao que decide a aventura de cada turno, isto e, o local e oq ocorre la. Depois de gerar ele retorna os valores */
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
    /*  Transicao do terreno para oq o jogador encontra */
    printf("e encontrou ");
    switch(y)
    {
        case(0):
            printf("um aldeao \n");
            acao_npc();
            break;
        case(1):
            printf("um comerciante \n");
            acao_comerciante();
            break;
        case(2):
            printf("um padre \n");
            acao_padre();
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
    if(x <= -1)
    {
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
        printf("Nome: %s", personagem.nome);
        printf("Level: %d \n", personagem.level);
        printf("Vida: %3d / %3d \n", personagem.vida_atual, personagem.vida_maxima);
        loop = gerador_aventura(rand() % 5, rand() % 5);
        printf("Pressione qualquer tecla para continuar... \n");
        getchar();
    }while(loop != -1);
    return -1;
}

/*  Funcao do NPC */
void acao_npc(void)
{
    int x;
    x = rand() % 3;
    printf("----------------------------------------- \n");
    printf("Aldeao: ");
    switch(x)
    {
        case(0):
            printf("Voce nao e bem vindo aqui \n");
            break;
        case(1):
            printf("Seu fim esta proximo... \n");
            break;
        case(2):
            printf("Um heroi, isso que este mundo precisa... \n");
            break;
    }
    printf("----------------------------------------- \n");
}

/*  Funcao do comerciante */
void acao_comerciante(void)
{
    int x, op;
    x = rand() % 2;
    printf("----------------------------------------- \n");
    printf("Comerciante: Bem vindo aventureiro! \n");
    printf("Gostaria de comprar ");
    switch(x)
    {
        case(0):
            printf("uma espada por 100 moedas de ouro? \n");
            printf("1. Sim \n");
            printf("2. Nao \n");
            printf("Opcao: ");
            scanf("%d", &op);
            setbuf(stdin, NULL);
            switch(op)
            {
                case(1):
                    if(personagem.ouro >= 100)
                    {
                        if(personagem.arma == 0)
                        {
                            printf("Hehe, volte sempre! \n");
                            personagem.ouro = personagem.ouro - 100;
                            personagem.arma++;
                        }
                        else
                        {
                            printf("Voce ja esta equipado com uma espada! \n");
                        }
                        
                    }
                    else
                    {
                        printf("Sem dinherio, sem arma! \n");
                    }
                    break;
                case(2):
                    printf("Que pena... \n");
                    break;
                default:
                    printf("Nao brinque comigo, quer saber? Vou embora que ganho mais! \n");
            }
            break;
        case(1):
            printf("uma armadura por 80 moedas de ouro? \n");
            printf("1. Sim \n");
            printf("2. Nao \n");
            printf("Opcao: ");
            scanf("%d", &op);
            setbuf(stdin, NULL);
            switch(op)
            {
                case(1):
                    if(personagem.ouro >= 80)
                    {
                        if(personagem.armadura == 0)
                        {
                            printf("Haha, nos vemos em breve! \n");
                            personagem.ouro = personagem.ouro - 80;
                            personagem.armadura++;
                        }
                        else
                        {
                            printf("Voce ja esta equipado com uma armadura! \n");
                        }
                        
                    }
                    else
                    {
                        printf("Voce nao tem ouro suficiente! \n");
                    }
                    break;
                case(2):
                    printf("Ok entao, nos vemos em breve! \n");
                    break;
                default:
                    printf("Nao brinque comigo, quer saber? Vou embora rapa! \n");
                    
            }
            break;
                case(2):
                    printf("um amuleto por 50 moedas de ouro? \n");
                    printf("1. Sim \n");
                    printf("2. Nao \n");
                    printf("Opcao: ");
                    scanf("%d", &op);
                    setbuf(stdin, NULL);
                    switch(op)
                    {
                        case(1):
                            if(personagem.ouro >= 50)
                            {
                                if(personagem.amuleto == 0)
                                {
                                    printf("E bom fazer negocios com voce! \n");
                                    personagem.ouro = personagem.ouro - 50;
                                    personagem.amuleto++;
                                }
                                else
                                {
                                    printf("Voce ja tem um amuleto equipado! \n");
                                }
                                
                            }
                            else
                            {
                                printf("Voce so tem %d de ouro, isso nao paga nada! \n", personagem.ouro);
                            }
                            
                            break;
                        case(2):
                            printf("OK, ate logo! \n");
                            break;
                            default:
                            printf("Nao brinque comigo, quer saber? Vou embora! \n");
                    }
                    break;
    }
    printf("----------------------------------------- \n");
}

/*  Funcao do padre */
void acao_padre(void)
{
    printf("----------------------------------------- \n");
    printf("Padre: ");
    if(personagem.vida_atual != personagem.vida_maxima)
    {
        printf("Vou curar suas feridas! Ate logo bravo aventureiro! \n");
        personagem.vida_atual = personagem.vida_maxima;
    }
    else
    {
        printf("Cuidado com os monstros desse mundo! \n");
    }
    printf("----------------------------------------- \n");
    
}

/*  Funcao do ladrao */
void acao_ladrao(void)
{
    printf("----------------------------------------- \n");
    printf("Em desenvolvimento! \n");
    printf("----------------------------------------- \n");
}

/*  Funcao do ogro */
void acao_ogro(void)
{
    printf("----------------------------------------- \n");
    printf("Em desenvolvimento! \n");
    printf("----------------------------------------- \n");
}

/*  Funcao que reseta o personagem */
void resetar_personagem(void)
{
    personagem.level = 1;
    personagem.xp = 0;
    personagem.ouro = 0;
    personagem.ataque = 5;
    personagem.vida_maxima = 20;
    personagem.vida_atual = personagem.vida_maxima;
    personagem.velocidade = 5;
    personagem.arma = 0;
    personagem.armadura = 0;
    personagem.amuleto = 0;
}

/*  Funcao que gera os inimigos */
void gerar_inimigos(void)
{
    /*  Lista de monstros */
    /*  Ladrao */
    strcpy(monstros[0].nome, "Ladrao");
    monstros[0].ataque = 3;
    monstros[0].vida_maxima = 10;
    monstros[0].vida_atual = monstros[0].vida_maxima;
    monstros[0].velocidade = 3;
    /*  Ogro */
    strcpy(monstros[1].nome, "Ogro");
    monstros[1].ataque = 2;
    monstros[1].vida_maxima = 15;
    monstros[1].vida_atual = monstros[1].vida_maxima;
    monstros[1].velocidade = 1;
}