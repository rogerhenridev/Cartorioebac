#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca�ao de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Bibliotea respons�vel por cuidar das strings

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite  o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s Salva na string, salva tudo dentro do cpf
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Abrindo o arquivo (W - cria/escreve)
	fprintf(file,cpf); //Salvar o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo
	fprintf(file,","); //Salvando dentro do arquivo
	fclose(file); //Fecha o oarquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); //Salvando na string
	
	file = fopen(arquivo, "a"); //Cria o arquivo
	fprintf(file,nome);
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo
	fprintf(file,",");
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome); //Perguntando ao usuario /Armazenando na vari�vel sobrenome
	
	file = fopen(arquivo,"a"); //Abrindo e salvando no arquivo (a - salva/atualiza��o)
	fprintf(file,sobrenome);
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo
	fprintf(file, ",");
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo); //Salvando na string
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo,"br"); //Colocando as informa��es dentro do arquivo, vari�vel cargo
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //%s chama a string
	
	FILE *file;
	file = fopen(cpf,"r"); //(r - ler o arquivo) le o arquivo CPF
	
	if(file == NULL) //Criando uma valida��o, caso o CPF nao esteja no sistema
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Buscando o arquivo
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); //Salvando na string
		printf("\n\n"); //Pulando linhas
	}
	
	system("pause"); //Pausa o programa para que ele n�o feche
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletavo: \n"); //Solocita o CPF para ser deletado do sistema
	scanf("%s", cpf); //Salvando na string
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if (file == NULL) //Caso o CPF n�o tenha sido cadastrado no sistema
	{
		printf("\n CPF de usu�rio nao localizado!\n");
		system("pause");
	}
	
	else 
	{
		if(remove(cpf) == 0) //Deletando o CPF do usu�rio
		{
			printf("\nCPF deletado com sucesso!\n");
			system("pause");
		}
	}

}




int main() //Inicio do programa
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //Limpa/apaga a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("### Cart�rio  da EBAC ###\n\n"); //Inicio da selecao
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("op��o: "); //Fim da selecao
		
		scanf("%d", &opcao); //%d variavel tipo inteira, Armazenando a escolha do usu�rio
		
		system("cls"); //Responsavel por limpar a tela
		
		switch(opcao) //Inicio do menu
		{
			case 1:
			registro(); //Chamada de fun��es
			break; //Fecha a chave
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o programa!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� disponiel!\n");
			system("pause");
			break;
	}	} //Fim do menu
	
}
