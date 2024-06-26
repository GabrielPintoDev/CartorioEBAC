#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//inicio da cria��o de vari�veis/strings
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF para cadastro: "); //coletando infos do usu�rio
	scanf("%s", cpf); //salvou na vari�vel cpf (%s refere-se a string)
	
	strcpy(arquivo, cpf); //copiou o valor de cpf para arquivo
	
	FILE *file; //cria o arquivo
	file = fopen (arquivo, "w"); //cria o arquivo ("W" significa escrever)
	fprintf(file,cpf); //salvo o valor da v�riavel
	fclose(file); //fecha o arquivo
	
	file = fopen (arquivo, "a"); //abre o arquivo
	fprintf(file,","); //adiciona a v�rgula para organiza��o do arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coleta a info do usu�rio
	scanf("%s", nome); //salva na vari�vel(string) nome 
	
	file = fopen (arquivo, "a"); //abre o arquivo
	fprintf(file, nome); //salvo o valor na vari�vel
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
	file = fopen(cpf, "r"); //l� o arquivo
	
	if(file == NULL) //se o arquivo n�o existir
	{
	  printf("O arquivo n�o foi localizado! \n");
    }
    
    while(fgets (conteudo, 200, file) != NULL) //se o arquivo existir
    {
    	printf ("\nEssas s�o as informa��es do usu�rio: ");
    	printf ("%s", conteudo);
    	printf ("\n\n");
	}
    
    system("pause");
    
}

int deletar()
{
	char cpf[40]; //cria string cpf
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coleta a info
	scanf("%s",cpf);	//salva a info na string
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL) //se o arquivo n�o existir
	{
		printf("O usu�rio n�o se encontra no sistema!. \n");
	}
	else //se o arquivo existir, apaga e aparece a mensagem
	{
		remove(cpf);
		printf("O usu�rio foi deletado com sucesso!. \n");
	}
	
	system("pause");
	
}

int main() 
{
	int opcao=0;//Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
    	
     system("cls"); //Limpa toda a tela
	
	 setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	 printf ("### Cart�rio da EBAC, seja bem-vindo! ### \n\n"); //inicio do menu
	 printf ("Escolha a op��o que voc� deseja no menu: \n\n");
	 printf ("\t1 - Registrar Nome\n");
	 printf ("\t2 - Consultar Nome\n");
	 printf ("\t3 - Deletar Nome\n\n"); 
	 printf ("\t4 - Sair do Sistema \n\n");
	 printf ("Op��o: ");  //final menu
	
	 scanf ("%d", &opcao); //armazenando escolhas do usu�rio
	
	 system("cls"); //limpa toda a tela
	 
	 
	  switch(opcao) //inicio da sele��o do menu
	  {
	 	case 1:
	 	 registro(); //chamada de fun��es de registro
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
		 printf("Est� op��o n�o existe!\n");
		 system("pause");
		 break;
		 
	  } //fim da sele��o
	
	 
	 
	 } 
    
}
