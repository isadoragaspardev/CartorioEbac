#include <stdio.h> //biblioteca de comunicação de usuário 
#include <stdlib.h> //biblioteca de aLocação de espaço em memória
#include <locale.h> //biblioteca de aLocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

		int registro() //função e variável
		{
		char arquivo[40]; //variável do tipo texto + nomemeando variável
		char cpf [40]; //variavel do tipo texto + nomeando variável
		char nome[40]; //variavel do tipo texto + nomeando variável
		char sobrenome[40]; //variavel do tipo texto + nomeando variável
		char cargo [40]; //variavel do tipo texto + nomeando variável
	
		printf("Digite o CPF a ser cadastrado: "); //mensagem ao cliente
		scanf("%s", cpf); //armazenando informação dentro da variavel CPF
	
		strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
		fprintf(file,cpf); //salva o valor da variável			
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //"a" atualizar
		fprintf(file,","); //colocar uma virgula
		fclose(file); //fecha o arquivo
	
		printf("Digite o nome a ser cadastrado: "); //mensagem ao usuário
		scanf("%s", nome); //armazena a resposta do usuário dentro de uma string
	
		file = fopen(arquivo, "a"); //abre o arquivo + atualiza
		fprintf(file,nome); //adiciona o nome colocado
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //"a" atualizar
		fprintf(file, ","); //colocar uma virgula
		fclose(file); //fecha o arquivo
	
		printf("Digite o sobrenome a ser cadastrado: "); //mensagem ao usuário
		scanf("%s", sobrenome); //armazena a resposta do usuário dentro de uma string
	
		file = fopen(arquivo, "a"); //abre o arquivo + atualiza
		fprintf(file,sobrenome); //adiciona o sobrenome
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //"a" atualizar
		fprintf(file,","); //colocar uma virgula
		fclose(file); //fecha o arquivo
	
		printf("Digite o cargo a ser cadastrado: "); //mensagem ao usuário
		scanf("%s",cargo); //armazena a resposta do usuário dentro de uma sting
	
		file = fopen(arquivo, "a"); //abre o arquivo + atuliza
		fprintf(file,cargo); //adiciona o cargo
		fclose(file); //fecha o arquivo
		
		system("pause"); //pausar a tela na opção escolhida
		}
		int consulta()
		{
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem e acentos 
	
		char cpf[40]; //definindo o tipo da variavel + quantidade
		char conteudo[200]; //definindo o tipo da variavel + quantidade
		
	
		printf("Digite o CPF a ser consultado: "); //mensagem ao usuário
		scanf("%s",cpf); //armazenando na string
	
		FILE *file; //abrir o arquivo
		file = fopen(cpf, "r"); //"r" ler o arquivo
	
		if(file == NULL) //se o arquivo for nulo  (nao existe)
		{
		printf("Não foi possivel abrir o arquivo, não localizado!. \n");
		}
		while(fgets(conteudo, 200, file) != NULL) //enquanto (buscar no arquivo) 200 que é o maximo dentro do arquivo de cpfs, se for mais que isso é NULO
		{	
		printf("\nEssas são as informações do usuário: "); //mensagema ao cliente
		printf("%s", conteudo); //todas as informações do usuário
		printf("\n\n"); //pular duas linhas
		}
		system("pause"); //pausar a tela na opção escolhida	
		fclose(file); //colocamos esse no final da consulta para fechar o arquivo		
		}
		int deletar()
		{
		char cpf[40]; //definindo o tipo da variavel
	
		printf("Digite o CPF do usuário a ser deletado: ");
		scanf("%s",cpf); //armazenando a informação dentro de uma string
	
		remove(cpf); //removendo o cpf 
	
		FILE *file; //buscando arquivo
		file = fopen(cpf,"r"); //abrindo arquivo e lendo 
	
		if(file == NULL); //caso o CPF não existir/for deletado 
		{
		printf("O usuário foi deletado do sistema!.\n");
		system("pause"); 	
		}	
		}
		
		int main() //função principal do menu
		{
		int opcao=0; //Definindo variaveis 
		int laco=1;	//Definindo a variavel de repetições
	
		for(laco=1;laco=1;) //repetições sempre ira voltar para o menu em vez de fechar
		{
		system("cls"); //limpar a tela
			
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem 
	
		printf("   Cartório da EBAC    \n\n"); //passar a mensagem ao cliente - inicio do menu + pular duas linhas
		printf(" Escolha a opção desejada do menu:\n\n"); //menu 
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d" , &opcao); //armazenar o valor que o usuario digitar na variavel
	
		system("cls"); //limpar a tela
		
			switch(opcao) //melhor opção para este tipo de menu/só chamar uma vez para a variavel que for trabalhar 
			{
			case 1: //caso a opção for 1 faça:
 			registro(); //chamar registro
 			break; //finalizar ou fechar ao fim da escolha
 			
 			case 2: //caso a opção for 2 faça:	
 			consulta(); //chamar consulta
			break; //finalizar ou fechar ao fim da escolha
		
			case 3: //caso a opção for 3 faça:	
			deletar(); //chamar deletar
			break; //finalizar ou fechar ao fim da escolha
			
			case 4: //caso a opção for 4 faça:
			printf("Obrigado por utilizar o sistema!\n"); //mensagem ao usuário
			return 0; //fechar o sistema
			break; //fechar
			
			default: //caso for diferente do padrão/não mapeamos
			printf("Esta opção nao está disponivel!\n"); //mensagem ao usuário
			system("pause"); //pausar a tela na opção escolhida	
			break; //finalizar ou fechar ao fim da escolha
			}			 
		}	

  }


