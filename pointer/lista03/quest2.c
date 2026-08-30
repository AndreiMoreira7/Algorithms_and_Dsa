#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Carro{
	char modelo[50];
	char dono[50];
	char placa[50];
	struct Carro* proximo;
}Carro;

typedef struct{
	Carro* inicio;
	Carro* fim;
	int total;
}Estacionamento;

void removerQuebraLinha(char *str){
	str[strcspn(str, "\n")] = '\0';
}

void inicializar(Estacionamento* est){
	est->inicio = NULL;
	est->fim = NULL;
	est->total = 0;
}

bool estVazio(Estacionamento* est){
	return est->inicio == NULL;
}

void adicionarCarro(Estacionamento* est, char modelo[], char dono[], char placa[]){
	Carro* novo = (Carro*) malloc (sizeof(Carro));
	if(novo == NULL) {
		printf("Erro ao alocar memória!"); 
		return;
	}
	
	strcpy(novo->modelo, modelo);
	strcpy(novo->dono, dono);
	strcpy(novo->placa, placa);
	novo->proximo = NULL;
	
	if(estVazio(est) == true){
		est->inicio = novo;
		est->fim = novo;
	}
	else{
		est->fim->proximo = novo;
		est->fim = novo; 
	}
	
	est->total++;
}

void removerCarro(Estacionamento* est, char placa[50]){
	if(estVazio(est) == true) printf("Estacionamento vazio, não há oque remover.");
	else{
		int tamanhoInicial = est->total;
		bool encontrado = false;
		
		for(int i = 0; i < tamanhoInicial; i++){
			Carro* atual = est->inicio;
			est->inicio = est->inicio->proximo;
			
			if(est->inicio == NULL) est->fim = NULL;
			
			if(strcmp(atual->placa, placa) == 0){
				free(atual);
				est->total--;
				
				printf("Carro de placa [%s] encontrado e liberado!\n", placa);
				encontrado = true;
				break;
			}
			else{
				atual->proximo = NULL;
				
				if(est->inicio == NULL){
					est->inicio = atual;
					est->fim = atual;
				}
				else{
					est->fim->proximo = atual;
					est->fim = atual;
				}
				printf("O carro de placa [%s] reentrou no estacionamento\n", atual->placa);
			}
		}
		
		if(!encontrado) printf("Carro de placa [%s] não foi encontrado", placa);
	}
}

void imprimirCarros(Estacionamento* est){
	if(estVazio(est) == true) printf("não há carros para mostrar, o estacionamento está vazio!");
	else{
		Carro* atual = est->inicio;
		printf("\n======= Lista de carros =======\n");
		while(atual != NULL){
			printf("\nModelo: %s\nDono: %s\nPlaca: %s\n", atual->modelo, atual->dono, atual->placa);
			atual = atual->proximo;
		}	
	}
}

int main(){
	Estacionamento est;
	inicializar(&est);
	
	int opcao = 0;
	bool validarLoop = true;
	char modelo[50], dono[50], placa[50];
	
	while(validarLoop == true){
		printf("\n\n======== Estacionamento ========\n");
		printf("1) Verificar se há carros no estacionamento\n");
		printf("2) Adicionar Carro\n");
		printf("3) Remover Carro\n");
		printf("4) Imprimir Carros\n");
		printf("5) Sair\n");
		printf("Digite uma opção: ");
		scanf("%d", &opcao);
		while(getchar() != '\n');
		
		switch(opcao){
			case 1: 
				if(estVazio(&est) == true) printf("O estacionamento está vazio!");
				else printf("Há carros no estacionamento");
				break;
			case 2: 
				printf("Digite o nome do dono do Carro: ");
				fgets(dono, sizeof(dono), stdin);
				removerQuebraLinha(dono);
				
				printf("Digite o modelo do carro: ");
				fgets(modelo, sizeof(modelo), stdin);
				removerQuebraLinha(modelo);
				
				printf("Digite a placa do carro: ");
				fgets(placa, sizeof(placa), stdin);
				removerQuebraLinha(placa);
				
				adicionarCarro(&est, modelo, dono, placa);
				break;
			case 3: 
				printf("Digite a placa do carro que quer remover: ");
				fgets(placa, sizeof(placa), stdin);
				removerQuebraLinha(placa);
				
				removerCarro(&est, placa);
				break;
			case 4: imprimirCarros(&est); break;
			case 5: validarLoop = false; break;
			default: printf("Digite uma opção válida!");
		}
	}
	
	return 0;
}