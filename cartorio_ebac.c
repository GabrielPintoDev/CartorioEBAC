#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//inicio da criação de variáveis/strings
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF para cadastro: "); //coletando infos do usuário
	scanf("%s", cpf); //salvou na variável cpf (%s refere-se a string)
	
	strcpy(arquivo, cpf); //copiou o valor de cpf para arquivo
	
	FILE *file; //cria o arquivo
	file = fopen (arquivo, "w"); //cria o arquivo ("W" significa escrever)
	fprintf(file,cpf); //salvo o valor da váriavel
	fclose(file); //fecha o arquivo
	
	file = fopen (arquivo, "a"); //abre o arquivo
	fprintf(file,","); //adiciona a vírgula para organização do arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coleta a info do usuário
	scanf("%s", nome); //salva na variável(string) nome 
	
	file = fopen (arquivo, "a"); //abre o arquivo
	fprintf(file, nome); //salvo o valor na variável
	fclose(file); //fecha o arquivo
	
	file = fopen (arquivo, "a"); //abre o arquivo
	fprintf(file,","); //adiciona a virgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen (arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40]; //cria a string cpf
	char conteudo[200]; //cria string conteudo
	
	printf("Digite o CPF a ser consultado: "); //coleta a info
	scanf("%s", cpf); //salva a info na string cpf
	
	FILE *file; //abre o arquivo
	file = fopen(cpf, "r"); //lê o arquivo
	
	if(file == NULL) //se o arquivo não existir
	{
	  printf("O arquivo não foi localizado! \n");
    }
    
    while(fgets (conteudo, 200, file) != NULL) //se o arquivo existir
    {
    	printf ("\nEssas são as informações do usuário: ");
    	printf ("%s", conteudo);
    	printf ("\n\n");
	}
    
    system("pause");
    
}

int deletar()
{
	char cpf[40]; //cria string cpf
	
	printf("Digite o CPF do usuário a ser deletado: "); //coleta a info
	scanf("%s",cpf);	//salva a info na string
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL) //se o arquivo não existir
	{
		printf("O usuário não se encontra no sistema!. \n");
	}
	else //se o arquivo existir, apaga e aparece a mensagem
	{
		remove(cpf);
		printf("O usuário foi deletado com sucesso!. \n");
	}
	
	system("pause");
	
}

int main() 
{
	int opcao=0;//Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
    	
     system("cls"); //Limpa toda a tela
	
	 setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	 printf ("### Cartório da EBAC, seja bem-vindo! ### \n\n"); //inicio do menu
	 printf ("Escolha a opção que você deseja no menu: \n\n");
	 printf ("\t1 - Registrar Nome\n");
	 printf ("\t2 - Consultar Nome\n");
	 printf ("\t3 - Deletar Nome\n\n"); 
	 printf ("\t4 - Sair do Sistema \n\n");
	 printf ("Opção: ");  //final menu
	
	 scanf ("%d", &opcao); //armazenando escolhas do usuário
	
	 system("cls"); //limpa toda a tela
	 
	 
	  switch(opcao) //inicio da seleção do menu
	  {
	 	case 1:
	 	 registro(); //chamada de funções de registro
		 break;
		
		case 2:
		 consulta();
		 break;
		
		case 3:
		 deletar();
		 break;
		
		case 4:
		  printf("Obrigado por utilizar o sistema!\n");
		  return 0;
		  break;
		  
		 default:
		 printf("Está opção não existe!\n");
		 system("pause");
		 break;
		 
	  } //fim da seleção
	
	 
	 
	 } 
    
}
