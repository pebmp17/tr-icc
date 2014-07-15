#include "stdio.h"
int mGerenCard();
int mkPedido();
int soliConta();



 int main(void)
{
	int optmainmenu=0;
	while (optmainmenu = 0){
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
				optmainmenu = 0;
				continue;
			default :
				puts("Opção Invalida");
		}
	}
	return 0;
}

int mGerenCard(){
	return 0;
}
int mkPedido(){
	return 0;
}
int soliConta(){
	return 0;
}