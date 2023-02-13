#include <stdio.h> //biblioteca de comunica��o com o usu�rio hihi
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];	
	
	printf("Por favor, informe o seu CPF:\n ");
	printf("CPF: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	
	printf("Por favor, informe o seu nome:\n ");
	printf("Nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	
	printf("Por favor, informe o seu sobrenome:\n ");
	printf("Sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	
	printf("Por favor, informe o seu cargo:\n ");
	printf("Cargo:");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	
	system("pause");
	 
	 
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	
	char cpf[40];
	char conteudo[200];
	
	    printf("Por favor, informe o CPF a ser consultado:\n ");
	    printf("CPF: ");
		scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Erro! CPF n�o encontrado!\n");     
	}
		       
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("Essas s�o as informa��es do usu�rio:\n\n ");
    	printf("%s", conteudo);
    	printf("\n\n");
    }
	
	system("pause");
	
	
	
}

int deletar()
{
	printf("Voc� escolheu deletar nomes!\n");
	system("pause");
}



int main()
    {
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
	
	    system("cls");
	

        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("###Cart�rio dos alunos da EBAC###\n\n"); //inicio do menu
	    printf("Escolha a op��o desejada no menu abaixo:\n\n");
	    printf("\t 1-Registrar nomes\n\n");
	    printf("\t 2-Consultar nomes\n\n");
	    printf("\t 3-Deletar nomes\n\n"); //fim do menu
        printf("Op��o:");
     
        scanf("%d", &opcao); //armazenando a escolha do usu�rio
    
        system("cls"); //limpar a tela
        
        
        switch(opcao)
        {
        	case 1:
        	registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o existe!\n");
			system("pause");
			break;
	

	
    	}
		         

    }
	
    
}
