#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocaçao de espaço em memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> //Bibliotea responsável por cuidar das strings

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite  o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s Salva na string, salva tudo dentro do cpf
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Abrindo o arquivo (W - cria/escreve)
	fprintf(file,cpf); //Salvar o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo
	fprintf(file,","); //Salvando dentro do arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); //Salvando na string
	
	file = fopen(arquivo, "a"); //Cria o arquivo
	fprintf(file,nome);
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo
	fprintf(file,",");
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome); //Perguntando ao usuario /Armazenando na variável sobrenome
	
	file = fopen(arquivo,"a"); //Abrindo e salvando no arquivo (a - salva/atualização)
	fprintf(file,sobrenome);
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo
	fprintf(file, ",");
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo); //Salvando na string
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo,"br"); //Colocando as informações dentro do arquivo, variável cargo
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
	
	if(file == NULL) //Criando uma validação, caso o CPF nao esteja no sistema
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Buscando o arquivo
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo); //Salvando na string
		printf("\n\n"); //Pulando linhas
	}
	
	system("pause"); //Pausa o programa para que ele não feche
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser deletavo: \n"); //Solocita o CPF para ser deletado do sistema
	scanf("%s", cpf); //Salvando na string
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if (file == NULL) //Caso o CPF não tenha sido cadastrado no sistema
	{
		printf("\n CPF de usuário nao localizado!\n");
		system("pause");
	}
	
	else 
	{
		if(remove(cpf) == 0) //Deletando o CPF do usuário
		{
			printf("\nCPF deletado com sucesso!\n");
			system("pause");
		}
	}

}




int main() //Inicio do programa
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //Limpa/apaga a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("### Cartório  da EBAC ###\n\n"); //Inicio da selecao
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("opção: "); //Fim da selecao
		
		scanf("%d", &opcao); //%d variavel tipo inteira, Armazenando a escolha do usuário
		
		system("cls"); //Responsavel por limpar a tela
		
		switch(opcao) //Inicio do menu
		{
			case 1:
			registro(); //Chamada de funções
			break; //Fecha a chave
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponiel!\n");
			system("pause");
			break;
	}	} //Fim do menu
	
}
