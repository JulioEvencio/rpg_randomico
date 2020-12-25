//  Bibliotecas
#include "rpg.h"
#include "rpg.c"
#include "personagem.c"
#include "inimigo.c"

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
/*  Funcao responsavel pelo sistema de luta do jogo */
void iniciar_luta(int x);
/*  Funcao do ataque do personagem */
void atacar_inimigo(int x);
/*  Funcao do ataque dos monstros */
void atacar_personagem(int x);
/*  Funcao que printa as estatisticas do usuario */
void printar_estatisticas(void);
/*  Funcao que controla os print das estatisticas durante a luta */
void controlar_dados(int x);
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
            printf("Um heroi! isso que este mundo precisa... \n");
            break;
    }
    printf("----------------------------------------- \n");
}

/*  Funcao do comerciante */
void acao_comerciante(void)
{
    int x, op;
    x = rand() % 3;
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
                            personagem.ataque = personagem.ataque + 1;
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
                            personagem.vida_maxima = personagem.vida_maxima + 5;
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
                                    personagem.velocidade = personagem.velocidade + 3;
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

/*  Funcao do ogro */
void acao_ogro(void)
{
    iniciar_luta(1);
}

/*  Funcao responsavel pelo sistema de luta do jogo */
void iniciar_luta(int x)
{
    int loop = 1;
    gerar_inimigos();
    printf("Pressione enter para continuar... \n");
    getchar();
    controlar_dados(x);
    printf("Pressione enter para iniciar o combate... \n");
    getchar();
    do
    {
        controlar_dados(x);
        if(personagem.velocidade > monstros[x].velocidade)
        {
            atacar_inimigo(x);
            if(monstros[x].vida_atual > 0)
            {
                atacar_personagem(x);
                if(personagem.vida_atual <= 0)
                {
                    printf("Voce morreu... \n");
                    loop = -1;
                }
            }
            else
            {
                printf("O inimigo morreu... \n");
                adicionar_ouro();
                loop = -1;
            }
            
        }
        else
        {
            atacar_personagem(x);
            if(personagem.vida_atual > 0)
            {
                atacar_inimigo(x);
                if(monstros[x].vida_atual <= 0)
                {
                    printf("O inimigo morreu... \n");
                    adicionar_ouro();
                    loop = -1;
                }
            }
            else
            {
                printf("Voce morreu... \n");
                loop = -1;
            }
            
        }
        
    } while (loop != -1);
    
}

/*  Funcao do ataque do personagem */
void atacar_inimigo(int x)
{
    monstros[x].vida_atual = monstros[x].vida_atual - personagem.ataque;
    controlar_dados(x);
    printf("Voce atacou o inimigo e causou %d de dano! \n", personagem.ataque);
    printf("Pressione enter para continuar... \n");
    getchar();
}

/*  Funcao do ataque dos monstros */
void atacar_personagem(int x)
{
    personagem.vida_atual = personagem.vida_atual - monstros[x].ataque;
    controlar_dados(x);
    printf("O inimigo atacou voce e causou %d de dano! \n", monstros[x].ataque);
    printf("Pressione enter para continuar... \n");
    getchar();
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

/*  Funcao que printa as estatisticas do usuario */
void printar_estatisticas(void)
{
    printf("Nome:   %s", personagem.nome);
    printf("Dia:    %d \n", personagem.dia);
    printf("Ouro:   %d \n", personagem.ouro);
    printf("Vida: %3d / %3d \n", personagem.vida_atual, personagem.vida_maxima);
}

/*  Funcao que controla os print das estatisticas durante a luta */
void controlar_dados(int x)
{
    system("clear");
    printf("--------------------------\n");
    printar_estatisticas();
    printf("--------------------------\n");
    printf("Inimigo: %s \n", monstros[x].nome);
    printf("Vida: %3d / %3d \n", monstros[x].vida_atual, monstros[x].vida_maxima);
    printf("--------------------------\n");
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