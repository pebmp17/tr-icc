#include <stdio.h>
#include <string.h>


int mGerenCard();
int mkPedido();
int soliConta();


int main(void)
{
    char optmainmenu=' ';
    puts ("Bem Vindo.");
    puts ("Qual opcao voce deseja usar?");
    puts ("1. Gerenciar itens do cardapio");
    puts ("2. Fazer um Pedido");
    puts ("3. Solicitar Conta");
    puts ("4. Sair do sistema");
    scanf ("%s", &optmainmenu);
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
    default:
    	puts("Opcao Invalida");
        puts ("Quais dessas opcoes voce deseja usar?");
        puts ("1. Gerenciar itens do cardapio");
        puts ("2. Fazer um Pedido");
        puts ("3. Solicitar Conta");
        puts ("4. Sair do sistema");
        scanf("%s",&optmainmenu);    
    }
    return 0;
}

int mGerenCard()
{
	int menuGerenItens(int n);
    char bOUc[15];
    int scape = 0;
    while (scape == 0)
    {
        puts ("Voce deseja gerenciar Bebidas ou Comidas?");
        scanf("%s", bOUc);
        if((strcmp(bOUc, "Bebidas") == 0) || (strcmp(bOUc, "bebidas")) == 0)
        {
            scape = 1;
            puts("\nBebidas");
            puts("--------");
            menuGerenItens(1);
        }
        else if ((strcmp(bOUc,"Comidas") == 0) || (strcmp(bOUc,"comidas") == 0))
        {
            scape = 1;
            puts("\nComidas");
            puts("--------");
            menuGerenItens(2);
        }
        else
        {
            puts("So e possivel gerenciar Comidas ou Bebidas");
        }
    }
    return 0;
    
}

int menuGerenItens(int n) {
	char gerenc[20];
	int scape2 = 0;
	while (scape2 == 0)
	{
		if (n = 1){
			puts("Voce deseja Cadastrar, Editar, Consultar ou Remover uma Bebida do cardapio?");
		}
		else if (n = 2)
		{
			puts("Voce deseja Cadastrar, Editar, Consultar ou Remover uma Comida do cardapio?");
		}
		scanf("%s",&gerenc);
		if((strcmp(gerenc, "Cadastrar") == 0) || (strcmp(gerenc, "cadastrar")) == 0) {
			if (n = 1)
			{
				scape2 = 1;
				//Cadastrar bebidas
			}
			else if (n = 2)
			{
				scape2 = 1;
				//Cadastrar Comidas
			}
		}
		else if((strcmp(gerenc, "Editar") == 0) || (strcmp(gerenc, "editar")) == 0){
			if (n=1)
			{
				scape2 = 1;
				//Editar bebidas
			}
			else if (n = 2)
			{
				scape2 = 1;
				//Editar Comidas
			}
		}
		else if((strcmp(gerenc, "Consultar") == 0) || (strcmp(gerenc, "consultar")) == 0){
			if (n=1)
			{
				scape2 = 1;
				//Consultar bebidas
			}
			else if (n = 2)
			{
				scape2 = 1;
				//Consultar Comidas
			}	
		}
		else if((strcmp(gerenc, "Remover") == 0) || (strcmp(gerenc, "remover")) == 0){
			if (n=1)
			{
				scape2 = 1;
				//Remover bebidas
			}
			else if (n = 2)
			{
				scape2 = 1;
				//Remover Comidas
			}	
		}
		else{
			puts ("Operaçao nao aceita");
		}
	}
}

int mkPedido()
{
    return 0;
}
int soliConta()
{
    return 0;
}
