#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mGerenCard();
int mkPedido();
int soliConta();
int cadastrar_Item(FILE *arq, int noi);
char optmainmenu= ' ';

int main()
{
	puts ("Bem Vindo.");
	puts ("Qual opcao voce deseja usar?");
	puts ("1. Gerenciar itens do cardapio");
	puts ("2. Fazer um Pedido");
	puts ("3. Solicitar Conta");
	puts ("4. Sair do sistema");
	scanf ("%s", &optmainmenu);
	while(optmainmenu != '4')
	{
		if (optmainmenu== '1')
		{
			puts("Opcao escolhida: 1.Gerenciar itens do cardapio");
			optmainmenu = ' ';
			mGerenCard();
			break;
		}
		else if(optmainmenu == '2'){
			puts("Opcao escolhida: 2.Fazer um Pedido");
			mkPedido();
			}
		else if (optmainmenu == '3'){
			puts ("Opcao escolhida: 3.Solicitar Conta");
			soliConta();
		}
		else if (optmainmenu == '4'){
			puts ("Opcao escolhida: 4.Sair do Sistema");
			optmainmenu = ' ';
		}
		else{
			puts("Opcao Invalida");
			puts ("Quais dessas opcoes voce deseja usar?");
			puts ("1. Gerenciar itens do cardapio");
			puts ("2. Fazer um Pedido");
			puts ("3. Solicitar Conta");
			puts ("4. Sair do sistema");
			scanf("%s",&optmainmenu);
		}
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
		puts ("Voce deseja gerenciar Bebidas ou Comidas, ou voltar ao menu?");
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
		 else if ((strcmp(bOUc,"Voltar") == 0) || (strcmp(bOUc,"voltar") == 0)){
				puts("");
				scape = 1;
				optmainmenu= ' ';
				main();
		 }
		else
		{
			puts("So e possivel gerenciar Comidas ou Bebidas");
		}
	}
	return 0;

}

int menuGerenItens(int n)
{
	int scape2 = 0;
	FILE *arq_geren;
	char gerenc[20];
	while (scape2 == 0)
	{
		if (n == 1)
		{
			puts("Voce deseja Cadastrar, Editar, Consultar ou Remover uma Bebida do cardapio ?");
		}
		else if (n == 2)
		{
			puts("Voce deseja Cadastrar, Editar, Consultar ou Remover uma Comida do cardapio?");
		}
		scanf("%s",gerenc);
		if((strcmp(gerenc, "Cadastrar") == 0) || (strcmp(gerenc, "cadastrar")) == 0)
		{
			if (n == 1)
			{
				arq_geren = fopen ("cardapio_bebidas.txt","a");
				if (arq_geren != NULL)
				{
					cadastrar_Item(arq_geren,n);
				}
				else
				{
					puts("Houve um erro ao abrir o cardapio de bebidas.");
				}
				scape2 =1;
			}
			else if (n == 2)
			{
				arq_geren = fopen ("cardapio_comdas.txt","a");
				if (arq_geren != NULL)
				{
					cadastrar_Item(arq_geren,n);
				}
				else
				{
					puts("Houve um erro ao abrir o cardapio de comidas.");
				}
				scape2 = 1;
				//Cadastrar Comidas
			}
		}
		else if((strcmp(gerenc, "Editar") == 0) || (strcmp(gerenc, "editar")) == 0)
		{
			if (n == 1)
			{
				scape2 = 1;
				//Editar bebidas
			}
			else if (n == 2)
			{
				scape2 = 1;
				//Editar Comidas
			}
		}
		else if((strcmp(gerenc, "Consultar") == 0) || (strcmp(gerenc, "consultar")) == 0)
		{
			if (n == 1)
			{
				scape2 = 1;
				//Consultar bebidas
			}
			else if (n == 2)
			{
				scape2 = 1;
				//Consultar Comidas
			}
		}
		else if((strcmp(gerenc, "Remover") == 0) || (strcmp(gerenc, "remover")) == 0)
		{
			if (n == 1)
			{
				scape2 = 1;
				//Remover bebidas
			}
			else if (n == 2)
			{
				scape2 = 1;
				//Remover Comidas
			}

		}
		else if((strcmp(gerenc, "Voltar") == 0) || (strcmp(gerenc, "voltar")) == 0)
		{
			puts("");
			scape2 = 1;
			main();
		}
		else
		{
			puts ("Operaçao nao aceita");
		}
	}
	return 0;
}
int cadastrar_Item (FILE *arq, int noi)
{
	char resp[10];
	FILE *arq_sis;
	char buffer[4];
	char temp[30];
	int codtemp = 0;
	if (noi == 1)
		puts("Qual bebida voce deseja cadastrar?");
	else if (noi == 2)
		puts("Qual comida voce deseja cadastrar?");
	scanf("%s",temp);
	arq_sis = fopen("sistema.txt","r");
	fread(buffer, 1, 1, arq_sis);
	fprintf(arq, "%s\n", temp);
	codtemp = atoi(buffer);
	codtemp = codtemp + 1;
	fclose(arq_sis);
	arq_sis = fopen("sistema.txt","w");
	fprintf(arq_sis,"%d", codtemp);
	fclose(arq_sis);
	fclose(arq);
	if (noi == 1)
	{
		printf("A bebida %s foi castrada com sucesso\n", temp);
		puts("");
		puts("Voce deseja cadastrar outra bebida?");
	}
	else if (noi == 2)
	{
		printf("A comida %s foi castrada com sucesso\n", temp);
		scanf("%s", resp);
	}
	if((strcmp(resp, "Sim") == 0) || (strcmp(resp, "sim")) == 0)
	{
		cadastrar_Item(arq, noi);
	}
	else if((strcmp(resp, "Nao") == 0) || (strcmp(resp, "nao")) == 0)
	{
	
	}
	else
	{
		puts("Digite Sim ou Nao");
	}
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
