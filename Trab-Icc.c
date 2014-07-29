#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int mGerenCard();
int mkPedido();
int soliConta();
int cadastrar_Item(FILE *arq, int noi);
int consultar_Item(FILE *arq, int noi);
int editar_Item(FILE *arq, int noi);
int remover_Item(FILE *arq, int noi);

char optmainmenu = ' ';
FILE *arq_sis;

struct cardapio {int codigo;char id;char nome_Item[30]; float preco;};
struct cardapio Item_Cardapio;
int main()
{
	if(access("sistema.txt",R_OK) == -1){
		arq_sis = fopen ("sistema.txt","w");
		fprintf(arq_sis, "1 1");
		fclose(arq_sis);
		system("clear");
	}
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
			break;
			}
		else if (optmainmenu == '3'){
			puts ("Opcao escolhida: 3.Solicitar Conta");
			soliConta();
			break;
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
				arq_geren = fopen ("cardapio_bebidas.bin","ab");
				if (arq_geren != NULL)
				{
					cadastrar_Item(arq_geren,n);
				}
				else
				{
					puts("Houve um erro ao abrir o cardapio de bebidas.");
				}
			}
			else if (n == 2)
			{
				arq_geren = fopen ("cardapio_comidas.bin","ab");
				if (arq_geren != NULL)
				{
					cadastrar_Item(arq_geren,n);
				}
				else
				{
					puts("Houve um erro ao abrir o cardapio de comidas.");
				}
			}
		}
		else if((strcmp(gerenc, "Editar") == 0) || (strcmp(gerenc, "editar")) == 0)
		{
			if (n == 1)
			{
				arq_geren = fopen ("cardapio_bebidas.bin","r+b");
				if (arq_geren != NULL)
				{
					editar_Item(arq_geren,n);
				}
				else
				{
					puts("Houve um erro ao abrir o cardapio de bebidas.");
				}
			}
			else if (n == 2)
			{
				arq_geren = fopen ("cardapio_comidas.bin","r+b");
				if (arq_geren != NULL)
				{
					editar_Item(arq_geren,n);
				}
				else
				{
					puts("Houve um erro ao abrir o cardapio de comidas.");
				}
			}
		}
		else if((strcmp(gerenc, "Consultar") == 0) || (strcmp(gerenc, "consultar")) == 0)
		{
			if (n == 1)
			{
				arq_geren = fopen ("cardapio_bebidas.bin","rb");
				if (arq_geren != NULL)
				{
					consultar_Item(arq_geren,n);
				}
				else
				{
					puts("Houve um erro ao abrir o cardapio de bebidas.");
				}
			}
			else if (n == 2)
			{
				arq_geren = fopen ("cardapio_comidas.bin","rb");
				if (arq_geren != NULL)
				{
					consultar_Item(arq_geren,n);
				}
				else
				{
					puts("Houve um erro ao abrir o cardapio de comidas.");
				}
			}
		}
		else if((strcmp(gerenc, "Remover") == 0) || (strcmp(gerenc, "remover")) == 0)
		{
			if (n == 1)
			{
				arq_geren = fopen ("cardapio_bebidas.bin","r+b");
				if (arq_geren != NULL)
				{
					remover_Item(arq_geren,n);
				}
				else
				{
					puts("Houve um erro ao abrir o cardapio de bebidas.");
				}
			}
			else if (n == 2)
			{
				arq_geren = fopen ("cardapio_comidas.bin","r+b");
				if (arq_geren != NULL)
				{
					remover_Item(arq_geren,n);
				}
				else
				{
					puts("Houve um erro ao abrir o cardapio de comidas.");
				}
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
	char spresso[10];
	int codnumBebi = 0, codnumComi = 0;
	char *tstspreso;
	if (noi == 1)
		puts("Qual bebida voce deseja cadastrar?");
	else if (noi == 2)
		puts("Qual comida voce deseja cadastrar?");
	scanf("%s",Item_Cardapio.nome_Item);
	while(codnumBebi == 0){
		printf("Qual o preco de %s ?\n", Item_Cardapio.nome_Item);
		scanf("%s", spresso);
		if (strtof(spresso, &tstspreso) == 0.0F){
			puts("Por favor digite um valor valido.");
		} 
		else
		{
			Item_Cardapio.preco = strtof(spresso, &tstspreso);
			break;
		}
	}
	arq_sis = fopen("sistema.txt","r");
	fscanf(arq_sis,"%d %d", &codnumBebi, &codnumComi);
	fclose(arq_sis);
	if (noi == 1)
	{
		Item_Cardapio.codigo = codnumBebi;
		codnumBebi = codnumBebi + 1;
		Item_Cardapio.id = 'b';
	}
	else if (noi == 2)
	{
		Item_Cardapio.codigo = codnumComi;
		codnumComi = codnumComi + 1;
		Item_Cardapio.id = 'c';
	}
	fwrite(&Item_Cardapio, sizeof(struct cardapio), 1, arq);
	arq_sis = fopen("sistema.txt","w");
	fprintf(arq_sis,"%d %d", codnumBebi, codnumComi);
	fclose(arq_sis);
	if (noi == 1)
	{
		printf("A bebida %s foi castrada com sucesso\n", Item_Cardapio.nome_Item);
		puts("");
		puts("Voce deseja cadastrar outra bebida?");
	}
	else if (noi == 2)
	{
		printf("A comida %s foi castrada com sucesso\n", Item_Cardapio.nome_Item);
		puts("");
		puts("Voce deseja cadastrar outra comida?");
	}
	scanf("%s", resp);
	if((strcmp(resp, "Sim") == 0) || (strcmp(resp, "sim")) == 0)
	{
		cadastrar_Item(arq, noi);
	}
	else if((strcmp(resp, "Nao") == 0) || (strcmp(resp, "nao")) == 0)
	{
		fclose(arq);
	}
	else
	{
		puts("Digite Sim ou Nao");
		cadastrar_Item (arq,noi);
	}
	return 0;
}

int consultar_Item (FILE *arq, int noi)
{
	struct cardapio ItemTemp;
	char resp[10], consult[30];
	int find = 0;
	if (noi == 1)
		puts("Qual bebida voce deseja consultar?");
	else if (noi == 2)
		puts("Qual comida voce deseja consultar?");
	scanf("%s",consult);
	rewind(arq);
	while ((!feof(arq)) && (find == 0))
	{
		fread(&ItemTemp, sizeof(struct cardapio), 1, arq);
		if (strcmp(ItemTemp.nome_Item, consult) == 0)
		{
			printf("Informacoes do Item %s:\n", ItemTemp.nome_Item);
			printf("%d%c %s R$:%.2f\n",ItemTemp.codigo, ItemTemp.id, ItemTemp.nome_Item, ItemTemp.preco);
			find = 1;
		}
	}
	if(find == 0)
	{
		puts("Item não encontrado");
	}
	if (noi == 1)
	{
		puts("Voce deseja consultar outra bebida?");
	}
	else if (noi == 2)
	{
		puts("Voce deseja consultar outra comida?");
	}
	scanf("%s", resp);
	if((strcmp(resp, "Sim") == 0) || (strcmp(resp, "sim")) == 0)
	{
		consultar_Item(arq, noi);
	}
	else if((strcmp(resp, "Nao") == 0) || (strcmp(resp, "nao")) == 0)
	{
		fclose(arq);
	}
	else
	{
		puts("Digite Sim ou Nao");
		consultar_Item (arq,noi);
	}
	return 0;
}

int editar_Item (FILE *arq, int noi)
{
	struct cardapio ItemTemp;
	char resp[10], consult[30], spresso[10];
	int find = 0;
	char *tstspreso;
	if (noi == 1)
		puts("Qual bebida voce deseja editar?");
	else if (noi == 2)
		puts("Qual comida voce deseja editar?");
	scanf("%s",consult);
	while ((!feof(arq)) && (find == 0))
	{
		fread(&ItemTemp, sizeof(struct cardapio), 1, arq);
		if (strcmp(ItemTemp.nome_Item, consult) == 0)
		{
			printf("Informacoes do Item %s:\n", ItemTemp.nome_Item);
			printf("%d%c %s R$:%.2f\n",ItemTemp.codigo, ItemTemp.id, ItemTemp.nome_Item, ItemTemp.preco);
			while(true)
			{
				printf("Digite o novo preco de %s\n", ItemTemp.nome_Item);
				scanf("%s", spresso);
				if (strtof(spresso, &tstspreso) == 0.0F){
					puts("Por favor digite um valor valido.");
				} 
				else
				{
					ItemTemp.preco = strtof(spresso, &tstspreso);
					fseek(arq, - sizeof(struct cardapio), SEEK_CUR);
					fwrite(&ItemTemp, sizeof(struct cardapio), 1, arq);
					break;
				}
			}
			find = 1;
		}
	}
	if(find == 0)
	{
		puts("Item não encontrado");
	}
	if (noi == 1)
	{
		puts("Voce deseja editar outra bebida?");
	}
	else if (noi == 2)
	{
		puts("Voce deseja editar outra comida?");
	}
	scanf("%s", resp);
	if((strcmp(resp, "Sim") == 0) || (strcmp(resp, "sim")) == 0)
	{
		editar_Item(arq, noi);
	}
	else if((strcmp(resp, "Nao") == 0) || (strcmp(resp, "nao")) == 0)
	{
		fclose(arq);
	}
	else
	{
		puts("Digite Sim ou Nao");
		editar_Item (arq,noi);
	}
	return 0;
}

int remover_Item (FILE *arq, int noi)
{
	struct cardapio ItemTemp;
	char resp[10];
	char consult [30];
	int find = 0;
	if (noi == 1)
		puts("Qual bebida voce deseja remover?");
	else if (noi == 2)
		puts("Qual comida voce deseja remover?");
	scanf("%s",consult);
	while ((!feof(arq)) && (find == 0))
	{
		fread(&ItemTemp, sizeof(struct cardapio), 1, arq);
		if (strcmp(ItemTemp.nome_Item, consult) == 0)
		{
			printf("Informacoes do Item %s:\n", ItemTemp.nome_Item);
			printf("%d%c %s R$:%f\n",ItemTemp.codigo, ItemTemp.id, ItemTemp.nome_Item, ItemTemp.preco);
			while(true){
				printf("Voce realmente deseja remover %s\n", ItemTemp.nome_Item);
				scanf("%s", resp);
				if ((strcmp(resp, "Sim") == 0) || (strcmp(resp, "sim")) == 0)
				{
					ItemTemp.codigo = 0;
					ItemTemp.id = ' ';
					ItemTemp.nome_Item[0] = 0;
					ItemTemp.preco = 0.0;
					fseek(arq, -sizeof(struct cardapio), SEEK_CUR);
					fwrite(&ItemTemp, sizeof(struct cardapio), 1, arq);
					printf("%s foi removido com sucesso\n", consult);
					find = 1;
					break;
				}
				else if ((strcmp(resp, "Nao") == 0) || (strcmp(resp, "nao")) == 0)
				{
					break;
				}
				else
				{
					puts("Digite Sim ou Nao");
				}
			}
		}
	}
	if(find == 0)
	{
		puts("Item não encontrado");
	}
	if (noi == 1)
	{
		puts("Voce deseja remover outra bebida?");
	}
	else if (noi == 2)
	{
		puts("Voce deseja remover outra comida?");
	}
	scanf("%s", resp);
	if((strcmp(resp, "Sim") == 0) || (strcmp(resp, "sim")) == 0)
	{
		remover_Item(arq, noi);
	}
	else if((strcmp(resp, "Nao") == 0) || (strcmp(resp, "nao")) == 0)
	{
		fclose(arq);
	}
	else
	{
		puts("Digite Sim ou Nao");
		remover_Item (arq,noi);
	}
	return 0;
}

int mkPedido()
{
	FILE *arq_com;
	FILE *arq_bebi;
	struct cardapio ItemCard;
	arq_bebi = fopen ("cardapio_bebidas.bin","r");
	if (arq_bebi == NULL)
	{
		puts("Nenhuma Bebida foi cadastrada");
	}
	else
	{
		puts("Bebidas Disponíveis:");
		while (!feof(arq_bebi))
		{
			fread(&ItemCard, sizeof(struct cardapio), 1, arq_bebi);
			printf("%d%c %s R$:%.2f\n",ItemCard.codigo, ItemCard.id, ItemCard.nome_Item, ItemCard.preco);
		}
	}
	puts(" ");
	arq_com = fopen ("cardapio_comidas.bin","r");
	if (arq_com == NULL)
	{
		puts("Nenhuma Comida foi cadastrada");
	}
	else
	{
		puts("Comidas Disponíveis:");
		while (!feof(arq_com))
		{
			fread(&ItemCard, sizeof(struct cardapio), 1, arq_com);
			printf("%d%c %s R$:%.2f\n",ItemCard.codigo, ItemCard.id, ItemCard.nome_Item, ItemCard.preco);
		}
	}
	main();
	return 0;
}

int soliConta()
{
	return 0;
}
