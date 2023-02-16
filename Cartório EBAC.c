#include <stdio.h> //biblioteca de comunica��o com o usu�rio hihi { 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria     s�o a primeira coisa a se botar num c�digo
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string }

int registro()  //fun��o respons�vel por cadastras os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];	
	//final da cria��o de vari�veis/string
	printf("Por favor, informe o seu CPF:\n "); //coletando informa��es do usu�rio
	printf("CPF: ");
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever = write
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); //para botar virgula no arquivo
	fclose(file); //fecha o arquivo
	
	
	printf("Por favor, informe o seu nome:\n "); //pedindo informa��o do usu�rio 
	printf("Nome: "); //deixando mais bonito visualmente
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file); //fechar arquivo
	
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); //virgula para deixar mais bonito visualmente
	fclose(file); //fechar arquivo
	
	
	printf("Por favor, informe o seu sobrenome:\n "); //pedindo mais informa�oes do usu�rio
	printf("Sobrenome: "); //mais bonito visualmente
	scanf("%s", sobrenome); //%s sempre se referindo ao string
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file); //fechar arquivo
	
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); //botar uma virgula para deixar melhor visualmente
	fclose(file); //fechar arquivo
	
	
	printf("Por favor, informe o seu cargo:\n "); //agora a ultima informa��o pedid
	printf("Cargo:"); //mais bonito visualmente
	scanf("%s", cargo); //%s refere-se a strings
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file); //fechar aquivo
	
	
	system("pause"); //deixar pausado para conseguir ver
	 
	 
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	// inicio cria��o de vari�vei/string
	char cpf[40]; //vari�vel cpf
	char conteudo[200]; //v�riavel conteudo
	
	    printf("Por favor, informe o CPF a ser consultado:\n "); //pedimos o cpf do usu�rio
	    printf("CPF: "); //para deixar mais bonito visualmente
		scanf("%s", cpf); //%s string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //cria o arquivo e o "r" � de read = ler
	
	if(file == NULL) //se o arquivo(cpf) n�o existir ou seja nulo = NULL
	{
		printf("Erro! CPF n�o encontrado!\n"); //aparecera isso    
	}
		       
    while(fgets(conteudo, 200, file) != NULL) //enquanto o arquivo for diferente igual a NULL
    {
    	printf("Essas s�o as informa��es do usu�rio:\n\n "); //aparecera isso
    	printf("%s", conteudo); //%s string
    	printf("\n\n"); //mais bonito visualmente
    }
	
	system("pause"); //pausar o sistema para poder ler
	
	fclose(file); //fechar o arquivo
	
	
}

int deletar()
{
	//inicio da cria��o de vari�veis/string
	char cpf[40]; //string pois o cpf cont�m mais de um valor. Variavel char seria apenas se fosse um unico valor
	
	printf("Por favor, informe o CPF a ser deletado:\n"); //pedindo o cpf do usu�rio
	printf("CPF: "); //deixar mais bonito visualmente
	scanf("%s", cpf ); //%s string do cpf
	
	remove(cpf); //vem de uma determinada biblioteca, est� fun��o s� serve para deletar
	
	FILE *file; //acessa a fun��o FILE na biblioteca o parametro file
	file = fopen(cpf, "r"); //ap�s acessar o file, abra o file/cpf
	
	if(file != NULL) //se o arquivo for diferente de nulo NULL 
	{
		fclose(file);
		remove(cpf);
		printf("\n");
		printf("Usu�rio deletado com sucesso!\n\n");
		printf("______________________________________________\n\n\n");
		system("pause");
	}   
	  
	else //mas se o arquivo for nulo
	{
		printf("\n");
	    printf("O usu�rio n�o se encontra no sistema! \n\n");
	    printf("______________________________________________\n\n\n");
		system("pause");
	}
	
	fclose(file); //fechar arquivo
}
     





int main()
    {
    setlocale(LC_ALL, "Portuguese");
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC###\n\n");
	printf("Login de administrador!\n\n");
	printf("Digite a sua senha:");
	scanf("%s", senhadigitada);
	system("cls");
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
	
	    for(laco=1;laco=1;)
        {
	
	         system("cls"); //limpar a tela
	

             setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	         printf("###Cart�rio dos alunos da EBAC###\n\n"); //inicio do menu
	        printf("Escolha a op��o desejada no menu abaixo:\n\n");
	         printf("\t1 - Registrar nomes\n\n");
	        printf("\t2 - Consultar nomes\n\n");
	        printf("\t3 - Deletar nomes\n\n"); 
	        printf("\t4 - Sair do sistema\n\n");
            printf("Op��o:");
     
            scanf("%d", &opcao); //armazenando a escolha do usu�rio
    
            system("cls"); //limpar a tela
        
        
            switch(opcao) //inicio da sele��o do menu
            {
            	case 1:
            	registro(); //chamada de fun��es
		    	break; //sempre botar para acabar uma fun��o
			
		    	case 2:
		    	consulta();
		    	break;
			
		    	case 3:
		    	deletar();
		    	break;
			
		    	case 4:
		    	printf("Obrigado por utilizar o sistema, volte sempre!\n");
		    	return 0;
		    	break;
			
		    	default:
			    printf("Essa op��o n�o existe!\n"); //para alguma op��o que n�o existe aparecera isso
		     	system("pause"); //pausar o sistema para poder ler
		    	break;
           }
            //fim da sele��o do menu
        }
    }
    
    else
        printf("Senha incorreta!");

 }
	
    
