//  Bibliotecas
#include "rpg.h"

/*  Funcoes */
//  Funcao responsavel pelo sistema de luta do jogo
void iniciar_luta(int x)
{
    int loop = 1;
    gerar_inimigos();
    printf("Pressione enter para continuar... \n");
    getchar();
    setbuf(stdin, NULL);
    controlar_dados(x);
    printf("Pressione enter para iniciar o combate... \n");
    getchar();
    setbuf(stdin, NULL);
    do
    {
        controlar_dados(x);
        if(personagem.velocidade > inimigo[x].velocidade)
        {
            atacar_inimigo(x);
            if(inimigo[x].vida_atual > 0)
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
                if(inimigo[x].vida_atual <= 0)
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

//  Funcao do ataque do personagem
void atacar_inimigo(int x)
{
    inimigo[x].vida_atual -= personagem.ataque;
    controlar_dados(x);
    printf("Voce atacou o inimigo e causou %d de dano! \n", personagem.ataque);
    printf("Pressione enter para continuar... \n");
    getchar();
    setbuf(stdin, NULL);
}