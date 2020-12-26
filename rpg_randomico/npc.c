//  Bibliotecas
#include "rpg.h"

/*  Funcoes */
/*  Funcao do Aldeao */
void acao_aldeao(void)
{
    int x;
    x = ALDEAO_FRASES;
    printf("----------------------------------------- \n");
    printf("Aldeao: ");
    switch(x)
    {
        case(ALDEAO_FRASE_1):
            printf("Voce nao e bem vindo aqui \n");
            break;
        case(ALDEAO_FRASE_2):
            printf("Seu fim esta proximo... \n");
            break;
        case(ALDEAO_FRASE_3):
            printf("Um heroi! isso que este mundo precisa... \n");
            break;
        default:
            printf("Esqueci o que ia falar... \n");
            break;
    }
}

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
        case(COMERCIANTE_ARMADURA):
            printf("uma armadura por 80 moedas de ouro? \n");
            printf("1. Sim \n");
            printf("2. Nao \n");
            printf("Opcao: ");
            scanf("%d", &op);
            setbuf(stdin, NULL);
            switch(op)
            {
                case(QUER_COMPRAR):
                    if(personagem.ouro >= ARMADURA_PRECO)
                    {
                        if(personagem.armadura == ARMADURA_BLOQUEADA)
                        {
                            printf("Haha, nos vemos em breve! \n");
                            personagem.ouro = personagem.ouro - ARMADURA_PRECO;
                            personagem.armadura++;
                            personagem.vida_maxima = personagem.vida_maxima + ARMADURA_PROTECAO;
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
                case(NAO_QUER_COMPRAR):
                    printf("Ok entao, nos vemos em breve! \n");
                    break;
                default:
                    printf("Nao brinque comigo, quer saber? Vou embora rapa! \n");
                    
            }
            break;
                case(COMERCIANTE_AMULETO):
                    printf("um amuleto por 50 moedas de ouro? \n");
                    printf("1. Sim \n");
                    printf("2. Nao \n");
                    printf("Opcao: ");
                    scanf("%d", &op);
                    setbuf(stdin, NULL);
                    switch(op)
                    {
                        case(QUER_COMPRAR):
                            if(personagem.ouro >= AMULETO_PRECO)
                            {
                                if(personagem.amuleto == AMULETO_BLOQUEADO)
                                {
                                    printf("E bom fazer negocios com voce! \n");
                                    personagem.ouro = personagem.ouro - AMULETO_PRECO;
                                    personagem.amuleto++;
                                    personagem.velocidade = personagem.velocidade + AMULETO_VELOCIDADE;
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
                        case(NAO_QUER_COMPRAR):
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
void acao_sacerdote(void)
{
    printf("----------------------------------------- \n");
    printf(SARCEDOTE_NOME);
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