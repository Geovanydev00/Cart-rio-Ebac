#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> // biblioteca de aloca��o  de texpo por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // fun��o respons�vel por cadastras os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por colocar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //w= cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // a = atualiza��o
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //  R = read 
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while((fgets(conteudo, 200, file)) != NULL)
	{
		printf("Essas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
  
}

int deletar()
{
	char cpf[40]; //Declarando vari�vel
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //Abrindo o arquivo para que possa ser lido o cpf
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
}


int main()
{
	int opcao=0; //definindo vari�veis
	int x=1; 
	
	for(x=1;x=1;) //Definindo um sistema de repeti��o 
	{
		
	system("cls");	
	
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	printf("### Cart�rio da EBAC ###\n\n"); //n�cio do menu
	printf("Por favor, escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n"); 
	printf("\t4 - Sair do sistema\n");
	printf("\nOp��o: ");//Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio(leia)
	
		system("cls"); //Limpando o sistema para quando for escolhido a op�ao, ir para a proxima p�gina
	
	
		switch(opcao)
		{
			case 1: 
			registro(); //chamada de fun��es
			break; 
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar esse sistema!\n");
			return 0;
			break;
			
			default:
			printf("Por favor, escolha um numero entre 1 e 3\n");
			system("pause");
			break;
			
		}
		
	}
}
