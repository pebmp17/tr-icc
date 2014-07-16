#include <strings.h>
#include "stdio.h"



int mGerenCard();
int mkPedido();
int soliConta();

int main(void)
{
    char optmainmenu='1';
    puts ("Bem Vindo.");
    puts ("Quais dessas opcoes voce deseja usar?");
    puts ("1. Gerenciar itens do cardapio");
    puts ("2. Fazer um Pedido");
    puts ("3. Solicitar Conta");
    puts ("4. Sair do sistema");
    gets (&optmainmenu);
    while ((optmainmenu>'4') ||(optmainmenu<'1'))
    {
        puts("Opcao Invalida");
        puts ("Quais dessas opcoes voce deseja usar?");
        puts ("1. Gerenciar itens do cardapio");
        puts ("2. Fazer um Pedido");
        puts ("3. Solicitar Conta");
        puts ("4. Sair do sistema");
        gets(&optmainmenu);
    }
    switch (optmainmenu)
    {
    case '1':
        puts("Opcao escolhida: 1.Gerenciar itens do cardapio");
        mGerenCard();
        break;
    case '2':
        puts("Opcao escolhida: 2.Fazer um Pedido");
        mkPedido();
        break;
    case '3':
        puts ("Opcao escolhida: 3.Solicitar Conta");
        soliConta();
        break;
    case '4':
        puts ("Opcao escolhida: 4.Sair do Sistema");
        break;
    }
    return 0;
}

int mGerenCard()
{
    /*int strcmp(const char*__s1, const char*__s2); */
    int menuGerenBebidas();
    int menuGerenComidas();
    char bOUc[15];
    int scape = 0;
    while (scape != 1)
    {
        puts ("Voce deseja gerenciar bebidas ou comidas?");
        scanf("%s", bOUc);
        if((strcmp(bOUc, "Bebidas") == 0) || (strcmp(bOUc, "bebidas")) == 0)
        {
            scape = 1;
            puts("Bebidas\n");
            menuGerenComidas();
        }
        else if ((strcmp(bOUc,"Comidas") == 0) || (strcmp(bOUc,"comidas") == 0))
        {
            scape = 1;
            puts("Comidas\n");
            menuGerenBebidas();
        }
        else
        {
            puts("So e possivel gerenciar Comidas ou Bebidas");
        }
    }
    return 0;

}
int menuGerenBebidas()
{
    return 0;
}
int menuGerenComidas()
{
    return 0;
}

int mkPedido()
{
    return 0;
}
int soliConta()
{
    return 0;
}
