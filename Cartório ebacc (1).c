#include <stdio.h> //biblioteca de comunica��o de usu�rio 
#include <stdlib.h> //biblioteca de aLoca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aLoca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

		int registro() //fun��o e vari�vel
		{
		char arquivo[40]; //vari�vel do tipo texto + nomemeando vari�vel
		char cpf [40]; //variavel do tipo texto + nomeando vari�vel
		char nome[40]; //variavel do tipo texto + nomeando vari�vel
		char sobrenome[40]; //variavel do tipo texto + nomeando vari�vel
		char cargo [40]; //variavel do tipo texto + nomeando vari�vel
	
		printf("Digite o CPF a ser cadastrado: "); //mensagem ao cliente
		scanf("%s", cpf); //armazenando informa��o dentro da variavel CPF
	
		strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
		fprintf(file,cpf); //salva o valor da vari�vel			
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //"a" atualizar
		fprintf(file,","); //colocar uma virgula
		fclose(file); //fecha o arquivo
	
		printf("Digite o nome a ser cadastrado: "); //mensagem ao usu�rio
		scanf("%s", nome); //armazena a resposta do usu�rio dentro de uma string
	
		file = fopen(arquivo, "a"); //abre o arquivo + atualiza
		fprintf(file,nome); //adiciona o nome colocado
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //"a" atualizar
		fprintf(file, ","); //colocar uma virgula
		fclose(file); //fecha o arquivo
	
		printf("Digite o sobrenome a ser cadastrado: "); //mensagem ao usu�rio
		scanf("%s", sobrenome); //armazena a resposta do usu�rio dentro de uma string
	
		file = fopen(arquivo, "a"); //abre o arquivo + atualiza
		fprintf(file,sobrenome); //adiciona o sobrenome
		fclose(file); //fecha o arquivo
	
		file = fopen(arquivo, "a"); //"a" atualizar
		fprintf(file,","); //colocar uma virgula
		fclose(file); //fecha o arquivo
	
		printf("Digite o cargo a ser cadastrado: "); //mensagem ao usu�rio
		scanf("%s",cargo); //armazena a resposta do usu�rio dentro de uma sting
	
		file = fopen(arquivo, "a"); //abre o arquivo + atuliza
		fprintf(file,cargo); //adiciona o cargo
		fclose(file); //fecha o arquivo
		
		system("pause"); //pausar a tela na op��o escolhida
		}
		int consulta()
		{
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem e acentos 
	
		char cpf[40]; //definindo o tipo da variavel + quantidade
		char conteudo[200]; //definindo o tipo da variavel + quantidade
		
	
		printf("Digite o CPF a ser consultado: "); //mensagem ao usu�rio
		scanf("%s",cpf); //armazenando na string
	
		FILE *file; //abrir o arquivo
		file = fopen(cpf, "r"); //"r" ler o arquivo
	
		if(file == NULL) //se o arquivo for nulo  (nao existe)
		{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
		}
		while(fgets(conteudo, 200, file) != NULL) //enquanto (buscar no arquivo) 200 que � o maximo dentro do arquivo de cpfs, se for mais que isso � NULO
		{	
		printf("\nEssas s�o as informa��es do usu�rio: "); //mensagema ao cliente
		printf("%s", conteudo); //todas as informa��es do usu�rio
		printf("\n\n"); //pular duas linhas
		}
		system("pause"); //pausar a tela na op��o escolhida	
		fclose(file); //colocamos esse no final da consulta para fechar o arquivo		
		}
		int deletar()
		{
		char cpf[40]; //definindo o tipo da variavel
	
		printf("Digite o CPF do usu�rio a ser deletado: ");
		scanf("%s",cpf); //armazenando a informa��o dentro de uma string
	
		remove(cpf); //removendo o cpf 
	
		FILE *file; //buscando arquivo
		file = fopen(cpf,"r"); //abrindo arquivo e lendo 
	
		if(file == NULL); //caso o CPF n�o existir/for deletado 
		{
		printf("O usu�rio foi deletado do sistema!.\n");
		system("pause"); 	
		}	
		}
		
		int main() //fun��o principal do menu
		{
		int opcao=0; //Definindo variaveis 
		int laco=1;	//Definindo a variavel de repeti��es
	
		for(laco=1;laco=1;) //repeti��es sempre ira voltar para o menu em vez de fechar
		{
		system("cls"); //limpar a tela
			
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem 
	
		printf("   Cart�rio da EBAC    \n\n"); //passar a mensagem ao cliente - inicio do menu + pular duas linhas
		printf(" Escolha a op��o desejada do menu:\n\n"); //menu 
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d" , &opcao); //armazenar o valor que o usuario digitar na variavel
	
		system("cls"); //limpar a tela
		
			switch(opcao) //melhor op��o para este tipo de menu/s� chamar uma vez para a variavel que for trabalhar 
			{
			case 1: //caso a op��o for 1 fa�a:
 			registro(); //chamar registro
 			break; //finalizar ou fechar ao fim da escolha
 			
 			case 2: //caso a op��o for 2 fa�a:	
 			consulta(); //chamar consulta
			break; //finalizar ou fechar ao fim da escolha
		
			case 3: //caso a op��o for 3 fa�a:	
			deletar(); //chamar deletar
			break; //finalizar ou fechar ao fim da escolha
			
			case 4: //caso a op��o for 4 fa�a:
			printf("Obrigado por utilizar o sistema!\n"); //mensagem ao usu�rio
			return 0; //fechar o sistema
			break; //fechar
			
			default: //caso for diferente do padr�o/n�o mapeamos
			printf("Esta op��o nao est� disponivel!\n"); //mensagem ao usu�rio
			system("pause"); //pausar a tela na op��o escolhida	
			break; //finalizar ou fechar ao fim da escolha
			}			 
		}	

  }


