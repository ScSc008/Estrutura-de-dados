#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

#define MAX_PESSOAS 100

struct Pessoa {
    int status;
    int id;    
    char nome[100];
    int idade;
    char cidade[100];
    char CPF[11];
    char email[100];
    char telefone[15];
};

struct Pessoa pessoa[MAX_PESSOAS];
int qtde = 0;


void inicializar(){
	int i;
	
	for(i = 0;i <= qtde;i++){
		pessoa[i].status = 0;
		pessoa[i].id = 0; 
		strcpy(pessoa[i].nome, "");     // Copia uma string vazia para nome
        pessoa[i].idade = 0;
        strcpy(pessoa[i].cidade, "");
        strcpy(pessoa[i].CPF, "");
        strcpy(pessoa[i].email, "");
        strcpy(pessoa[i].telefone, "");
		
	}
}

void inserir() {
    if (qtde < MAX_PESSOAS) {
        pessoa[qtde].status = 1;
                
		pessoa[qtde].id = qtde + 1;
	
        printf("\nDigite o nome: ");
        fflush(stdin);
        fgets(pessoa[qtde].nome, 100, stdin);

        printf("Digite a idade: ");
        fflush(stdin);
        scanf("%d", &pessoa[qtde].idade);

        printf("Digite o CPF: ");
       fflush(stdin);
        fgets(pessoa[qtde].CPF, 11, stdin);

        printf("Digite o email: ");
        fflush(stdin);
        fgets(pessoa[qtde].email, 100, stdin);

        printf("Digite a cidade: ");
        fflush(stdin);
        fgets(pessoa[qtde].cidade, 100, stdin);

        printf("Digite o telefone: ");
        fflush(stdin);
        fgets(pessoa[qtde].telefone, 15, stdin);

        qtde++;
    } else {
        printf("Limite de cadastros atingido!\n");
    }
}

void alterar() {
    int ref, i, b = 0;
    if(qtde > 0){
    	    printf("\nColoque o ID do cliente para alteração (1 a %d): ", qtde);
    scanf("%d", &ref);

	
	for(i = 0;i<=qtde;i++){ 	
	    if (pessoa[i].id == ref){
	    	printf("\nNome: %s", pessoa[ref-1].nome);
    		printf("CPF: %s", pessoa[ref-1].CPF);
	    	
			int opcao, b = 1;
	        printf("\nO que deseja alterar?\n");
	        printf("1 - Nome\n");
	        printf("2 - Idade\n");
	        printf("3 - CPF\n");
	        printf("4 - Email\n");
	        printf("5 - Cidade\n");
	        printf("6 - Telefone\n");
	        printf("Informe uma opção: ");
	        scanf("%d", &opcao);
	
	        switch (opcao) {
	            case 1:
	                printf("\nDigite o novo nome: ");
	                fflush(stdin);
	                fgets(pessoa[ref-1].nome, 100, stdin);
	                break;
	            case 2:
	                printf("\nDigite a nova idade: ");
	                fflush(stdin);
	                scanf("%d", &pessoa[ref-1].idade);
	                break;
	            case 3:
	                printf("\nDigite o novo CPF: ");
	                fflush(stdin);
	                fgets(pessoa[ref-1].CPF, 11, stdin);
	                break;
	            case 4:
	                printf("\nDigite o novo email: ");
	                fflush(stdin);
	                fgets(pessoa[ref-1].email, 100, stdin);
	                break;
	            case 5:
	                printf("\nDigite a nova cidade: ");
	                fflush(stdin);
	                fgets(pessoa[ref-1].cidade, 100, stdin);
	                break;
	            case 6:
	                printf("\nDigite o novo telefone: ");
	                fflush(stdin);
	                fgets(pessoa[ref-1].telefone, 15, stdin);
	                break;
	            default:
	                printf("Opção inválida!\n");
	                break;
	        }
	    }
	    if(b = 1){
	    	printf("\nCadastro alterado com sucesso!!!");
		}
	       
    }
    
    if(b = 0){
	        printf("ID inválido!\n\n");
		}
    
	}else
	printf("Ainda não há nenhum cadastro");
	system("pause");
}

void inativar(){
	int i, cod;
	
	printf("Informe o ID do cadastro: ");
	scanf("%d", &cod);
	
	for(i = 0;i<=qtde;i++){ 
	
	    if (pessoa[i].id == cod){ 
			if(pessoa[i].status = 0){
				printf("O cadastro já esta inativo");
				system("pause");
			}else{
				pessoa[i].status = 0;
				printf("O cadastro foi inativado!");
				system("pause");
			}     
		}
	}
}

void ativar(){
	int i, cod;
	
	printf("Informe o ID do cadastro: ");
	scanf("%d", &cod);
	
	for(i = 0;i<=qtde;i++){ 
	
	    if (pessoa[i].id == cod){  
			if(pessoa[i].status == 0){
				pessoa[i].status = 1;
				printf("O cadastro foi ativado!");
				system("pause");
			}else{   
	    		printf("O cadastro já esta ativo");
	    		system("pause");
			}
		}
	}
}

void exibir(){
	int i;
	
	for(i = 0;i <= qtde;i++){
		if(pessoa[i].status == 1){
			printf("Id: %d", pessoa[i].id);
			printf("\nNome: %s", pessoa[i].nome);
			printf("Idade: %d", pessoa[i].idade);
			printf("\nCidade: %s", pessoa[i].cidade);
			printf("CPF: %s", pessoa[i].CPF);
			printf("Email: %s", pessoa[i].email);
			printf("Telefone: %s", pessoa[i].telefone);
			printf("\n\n");
		}
	}
}

void gravar_arquivo(){
	FILE *arq;
	int i;
	system("cls");
	printf("<<Gravando Registros no Arquivo>>\n\n");
	arq = fopen("Cadastro_Pessoa.bin", "wb");
	if(arq == NULL){
		printf("Erro ao abrir o arquivo!!!");
	}
	else{	
			fwrite(&pessoa[i], sizeof(struct Pessoa), 1, arq);
		}
		fclose(arq);
		printf("Registros Gravados com Sucesso!!!");
		system("pause");
	}
	


void ler_arquivo(){
	int i;
	FILE *arq;
	printf("<<Lendo Arquivo de Registros>>\n\n");
	arq = fopen("Cadastro_Pessoa.bin", "rb");
	if (arq ==NULL){
		printf("Erro ao abrir o arquivo!!!");
	}
	else{
		i = 0;
		while(fread(&pessoa[i], sizeof(struct Pessoa), 1, arq) > 0){
			i++;
		}
		fclose(arq);
		printf("Registros Lidos com Sucesso!!!");
		system("pause");
	}
}

void excluir_arquivo(){
FILE *arq;
	int i;
	system("cls");
	printf("<<Excluindo Registros no Arquivo>>\n\n");
	arq = fopen("Cadastro_Pessoa.bin", "wb");
	fclose(arq);
	printf("Registros Excluídos com Sucesso!!!");
	system("pause");
}
 

/*void ordenar_idade(){
 int elemento, houveTroca, indice;
    int tamanho = qtde;
    do {
        houveTroca = 0;
        for (indice = 0; indice < tamanho - 1; indice++) {
            if (pessoa[indice].idade > pessoa[indice + 1].idade) {
                elemento = pessoa[indice].idade;
                pessoa[indice].idade = pessoa[indice + 1].idade;
                pessoa[indice + 1].idade = elemento;
                houveTroca = 1;
            }
        }
        tamanho--;
    }
    while (houveTroca == 1);
}*/
void trocar(struct Pessoa *a, struct Pessoa *b) {
    struct Pessoa temp = *a;
    *a = *b;
    *b = temp;
}

void ordenar_idade() {
    int esq, dir;

    for (esq = 0; esq < qtde - 1; esq++) {
        for (dir = esq + 1; dir < qtde; dir++) {
            if (pessoa[esq].idade > pessoa[dir].idade) {
                trocar(&pessoa[esq], &pessoa[dir]);
            }
        }
    }
    
    exibir();
}

const char* cumprimento() {
    time_t agora;
    
    struct tm *info;
    
    time(&agora);
    info = localtime(&agora);
    
    int hr = info->tm_hour; 

    if (hr >= 5 && hr < 12) {
        return "Bom dia";
    } 
	else{
		if(hr >= 12 && hr < 18) {
        	return "Boa tarde";
	    } 
		else{
        	return "Boa noite";
		}
    }
}

/* MENU */
void menu() {
	int resposta;
	
	printf("0 - Sair do programa\n");
	printf("1 - Inserir Dados\n");
	printf("2 - Alterar Dados \n");
	printf("3 - Inativar Cadastro\n");
	printf("4 - Ativar Cadastro \n");
	printf("5 - Exibir\n");
	printf("6 - Gravar Arquivo\n");
	printf("7 - Recuperar Arquivo\n");
	printf("8 - Excluir Arquivo\n");
	printf("9 - Ordenar por idade\n");
	printf("Informe uma opção: \n");
	scanf("%d", &resposta);
	printf("\n");
		
		switch(resposta){
			case 0:
				system("cls");
				break;
			case 1:
				inserir();
				break;
			case 2:
				alterar();
				break;
			case 3:
				inativar();
				break;
			case 4:
				ativar();
				break;
			case 5:
				exibir();
				system("pause");
				break;
			case 6:
				gravar_arquivo();
				break;
			case 7:
				ler_arquivo();
				break;
			case 8:
				excluir_arquivo();
				break;
			case 9:
				ordenar_idade();
				system("pause");
				break;
			default:
				printf("Esta opção é inválida, por favor selecione outra\n");
				system("pause");
				break;
		}
		
		if(resposta != 0){
			system("cls");
			menu();
		}
		if(resposta != 5){
			system("cls");
		}
}


int main() {
	char username[150];
	const char* cumpriment = cumprimento();
	
    setlocale(LC_ALL, "portuguese");
    DWORD username_len = sizeof(username); 
     
    if (GetUserName(username, &username_len)){
		printf(">>>%s, %s! Bem-vindo ao sistema!<<<\n", cumpriment, username);
        printf(">>>Aperte qualquer tecla para acessar o menu<<<\n\n\n\n");
		system("pause");                                              
		system("cls");
    }
	else{
		printf(">>>%s! Bem-vindo ao sistema!<<<\n", cumpriment);
        printf(">>>Aperte qualquer tecla para acessar o menu<<<\n\n\n\n");
		system("pause");
		system("cls");
    }
    
    menu();
    
    printf(">>>Desconectando... Estaremos aqui quando você voltar!<<<\n");
	printf(">>>Até a próxima, %s<<<\n", username);
	
    return 0;

}
