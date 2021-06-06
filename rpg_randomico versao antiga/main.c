//  Bibliotecas
#include "rpg.h"
#include "rpg.c"
#include "personagem.c"
#include "npc.c"
#include "inimigo.c"
#include "luta.c"

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
    fgets(personagem.nome, PERSONAGEM_NOME, stdin);
    remover_enter(personagem.nome, PERSONAGEM_NOME);
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