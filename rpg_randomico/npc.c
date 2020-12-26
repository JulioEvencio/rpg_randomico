//  Bibliotecas
#include "rpg.h"

/*  Funcoes */
/*  Funcao do comerciante */
void acao_comerciante(void)
{
    int x, op;
    x = COMERCIANTE_VENDAS;
    printf("----------------------------------------- \n");
    printf("Comerciante: Bem vindo aventureiro! \n");
    printf("Gostaria de comprar ");
    switch(x)
    {
        case(COMERCIANTE_ARMA):
            printf("uma espada por 100 moedas de ouro? \n");
            printf("1. Sim \n");
            printf("2. Nao \n");
            printf("Opcao: ");
            scanf("%d", &op);
            setbuf(stdin, NULL);
            switch(op)
            {
                case(QUER_COMPRAR):
                    if(personagem.ouro >= ESPADA_PRECO)
                    {
                        if(personagem.arma == ESPADA_BLOQUEADA)
                        {
                            printf("Hehe, volte sempre! \n");
                            personagem.ouro = personagem.ouro - ESPADA_PRECO;
                            personagem.arma++;
                            personagem.ataque = personagem.ataque + ESPADA_ATAQUE;
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
                case(NAO_QUER_COMPRAR):
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