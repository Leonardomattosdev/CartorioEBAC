#include <stdio.h> //biblioteca de comunicação com o usuário hihi
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

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
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
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
		printf("Erro! CPF não encontrado!\n");     
	}
		       
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("Essas são as informações do usuário:\n\n ");
    	printf("%s", conteudo);
    	printf("\n\n");
    }
	
	system("pause");
	
	
	
}

int deletar()
{
	printf("Você escolheu deletar nomes!\n");
	system("pause");
}



int main()
    {
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
	
	    system("cls");
	

        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("###Cartório dos alunos da EBAC###\n\n"); //inicio do menu
	    printf("Escolha a opção desejada no menu abaixo:\n\n");
	    printf("\t 1-Registrar nomes\n\n");
	    printf("\t 2-Consultar nomes\n\n");
	    printf("\t 3-Deletar nomes\n\n"); //fim do menu
        printf("Opção:");
     
        scanf("%d", &opcao); //armazenando a escolha do usuário
    
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
			printf("Essa opção não existe!\n");
			system("pause");
			break;
	

	
    	}
		         

    }
	
    
}
