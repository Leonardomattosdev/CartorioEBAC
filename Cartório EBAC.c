#include <stdio.h> //biblioteca de comunicação com o usuário hihi { 
#include <stdlib.h> //biblioteca de alocação de espaço em memória     são a primeira coisa a se botar num código
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string }

int registro()  //função responsável por cadastras os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];	
	//final da criação de variáveis/string
	printf("Por favor, informe o seu CPF:\n "); //coletando informações do usuário
	printf("CPF: ");
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever = write
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); //para botar virgula no arquivo
	fclose(file); //fecha o arquivo
	
	
	printf("Por favor, informe o seu nome:\n "); //pedindo informação do usuário 
	printf("Nome: "); //deixando mais bonito visualmente
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file); //fechar arquivo
	
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); //virgula para deixar mais bonito visualmente
	fclose(file); //fechar arquivo
	
	
	printf("Por favor, informe o seu sobrenome:\n "); //pedindo mais informaçoes do usuário
	printf("Sobrenome: "); //mais bonito visualmente
	scanf("%s", sobrenome); //%s sempre se referindo ao string
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file); //fechar arquivo
	
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); //botar uma virgula para deixar melhor visualmente
	fclose(file); //fechar arquivo
	
	
	printf("Por favor, informe o seu cargo:\n "); //agora a ultima informação pedid
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
	
	// inicio criação de variávei/string
	char cpf[40]; //variável cpf
	char conteudo[200]; //váriavel conteudo
	
	    printf("Por favor, informe o CPF a ser consultado:\n "); //pedimos o cpf do usuário
	    printf("CPF: "); //para deixar mais bonito visualmente
		scanf("%s", cpf); //%s string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //cria o arquivo e o "r" é de read = ler
	
	if(file == NULL) //se o arquivo(cpf) não existir ou seja nulo = NULL
	{
		printf("Erro! CPF não encontrado!\n"); //aparecera isso    
	}
		       
    while(fgets(conteudo, 200, file) != NULL) //enquanto o arquivo for diferente igual a NULL
    {
    	printf("Essas são as informações do usuário:\n\n "); //aparecera isso
    	printf("%s", conteudo); //%s string
    	printf("\n\n"); //mais bonito visualmente
    }
	
	system("pause"); //pausar o sistema para poder ler
	
	fclose(file); //fechar o arquivo
	
	
}

int deletar()
{
	//inicio da criação de variáveis/string
	char cpf[40]; //string pois o cpf contém mais de um valor. Variavel char seria apenas se fosse um unico valor
	
	printf("Por favor, informe o CPF a ser deletado:\n"); //pedindo o cpf do usuário
	printf("CPF: "); //deixar mais bonito visualmente
	scanf("%s", cpf ); //%s string do cpf
	
	remove(cpf); //vem de uma determinada biblioteca, está função só serve para deletar
	
	FILE *file; //acessa a função FILE na biblioteca o parametro file
	file = fopen(cpf, "r"); //após acessar o file, abra o file/cpf
	
	if(file != NULL) //se o arquivo for diferente de nulo NULL 
	{
		fclose(file);
		remove(cpf);
		printf("\n");
		printf("Usuário deletado com sucesso!\n\n");
		printf("______________________________________________\n\n\n");
		system("pause");
	}   
	  
	else //mas se o arquivo for nulo
	{
		printf("\n");
	    printf("O usuário não se encontra no sistema! \n\n");
	    printf("______________________________________________\n\n\n");
		system("pause");
	}
	
	fclose(file); //fechar arquivo
}
     





int main()
    {
    setlocale(LC_ALL, "Portuguese");
	int opcao=0; //Definindo variáveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC###\n\n");
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
	
	         printf("###Cartório dos alunos da EBAC###\n\n"); //inicio do menu
	        printf("Escolha a opção desejada no menu abaixo:\n\n");
	         printf("\t1 - Registrar nomes\n\n");
	        printf("\t2 - Consultar nomes\n\n");
	        printf("\t3 - Deletar nomes\n\n"); 
	        printf("\t4 - Sair do sistema\n\n");
            printf("Opção:");
     
            scanf("%d", &opcao); //armazenando a escolha do usuário
    
            system("cls"); //limpar a tela
        
        
            switch(opcao) //inicio da seleção do menu
            {
            	case 1:
            	registro(); //chamada de funções
		    	break; //sempre botar para acabar uma função
			
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
			    printf("Essa opção não existe!\n"); //para alguma opção que não existe aparecera isso
		     	system("pause"); //pausar o sistema para poder ler
		    	break;
           }
            //fim da seleção do menu
        }
    }
    
    else
        printf("Senha incorreta!");

 }
	
    
