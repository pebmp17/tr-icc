#include <strings.h>
#include "stdio.h"



int mGerenCard();
int mkPedido();
int soliConta();

 int main(void)
{
	int optmainmenu= 1;
	while (optmainmenu != 4){
		puts ("Bem Vindo.");
		puts ("Quais dessas opçoes voce deseja usar?");
		puts ("1. Gerenciar itens do cardapio");
		puts ("2. Fazer um Pedido");
		puts ("3. Solicitar Conta");
		puts ("4. Sair do sistema");
		scanf ("%d", &optmainmenu);
		switch (optmainmenu){
			case 1:
				puts("Opção escolhida: 1.Gerenciar itens do cardapio");
				mGerenCard();
				break;
			case 2:
				puts("Opção escolhida: 2.Fazer um Pedido");
				mkPedido();
				break;
			case 3:
				puts ("Opção escolhida: 3.Solicitar Conta");
				soliConta();
				break;
			case 4:
				puts ("Opção escolhida: 4.Sair do Sistema");
				continue;
			default :
				puts("\nOpção Invalida");
		}
	}
	return 0;
}

int mGerenCard(){
	int strcmp(const char*__s1, const char*__s2);
	int menuGerenBebidas();
	int menuGerenComidas();
	char bOUc[15];
	int scape = 0;
	scanf("%s", bOUc);
	while (scape != 1){
		puts ("Voce deseja gerenciar bebidas ou comidas?");
		if((strcmp(bOUc, "Bebidas") == 0) ||  (strcmp(bOUc, "Bebidas")) == 0){
			scape = 1;
		  menuGerenComidas();
		}
		else if ((strcmp(bOUc,"Comidas") == 0) || (strcmp(bOUc,"comidas") == 0)){
			scape = 1;
			menuGerenBebidas();
		}
		else 
		{
			puts("Só é possivel gerenciar Comidas ou Bebidas");
		}
	}
	return 0;
	
}
int menuGerenBebidas()
	{
		return 0;
	}

int mkPedido(){
	return 0;
}
int soliConta(){
	return 0;
}
