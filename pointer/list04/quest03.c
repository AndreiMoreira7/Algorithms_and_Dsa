#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Cidade{
	char nome[50];
	float distancia;
	struct Cidade* proxima;
}Cidade;

typedef struct{
	Cidade* origem;
	Cidade* destino;
	int numCidades;
}Trajeto;

void limparQuebraLinha(char* str){
	str[strcspn(str, "\n")] = '\0';
}

void inicializar(Trajeto* trajeto){
	trajeto->origem = NULL;
	trajeto->destino = NULL;
	trajeto->numCidades = 0;
}

bool trajetoVazio(Trajeto* trajeto){
	return trajeto->origem == NULL;
}

void enfileirar(Trajeto* trajeto, char cidade[], float distancia){
	Cidade* nova = (Cidade*) malloc (sizeof(Cidade));
	if(nova == NULL){ printf("Erro ao alocar memória!"); exit(EXIT_FAILURE);}
	
	strcpy(nova->nome, cidade);
	nova->distancia = distancia;
	nova->proxima = NULL;
	
	if(trajetoVazio(trajeto) == true){
		trajeto->origem = nova;
		trajeto->destino = nova;
	}
	else{
		trajeto->destino->proxima = nova;
		trajeto->destino = nova;
	}
	trajeto->numCidades++;
}

void alocarCidade(Trajeto* trajeto){
	char nome[50];
	float distancia = 0.0;
	
	if(trajetoVazio(trajeto) == true){
		printf("Digite o nome da cidade de Origem: ");
		fgets(nome, sizeof(nome), stdin);
		limparQuebraLinha(nome);
		
		enfileirar(trajeto, nome, distancia);
	}
	else{
		printf("Digite o nome da cidade: ");
		fgets(nome, sizeof(nome), stdin);
		limparQuebraLinha(nome);
		
		printf("Digite a distância em [km] da cidade anterior para a atual: ");
		scanf("%f", &distancia);
		while(getchar() != '\n');
		
		enfileirar(trajeto, nome, distancia);
	}
}

void imprimirTrajeto(Trajeto* trajeto){
	if(trajetoVazio(trajeto) == true) printf("Ainda não escolheu para onde viajar!");
	else{
		Cidade* aux = trajeto->origem;
		float kmPercorrido = 0.0;
		int numCidade = 1;
	
		printf("\n======== Trajeto ========\n");
	
		while(aux != NULL){
			kmPercorrido += aux->distancia;
			if(numCidade == 1){
				printf("Cidade %d | %s (%.2f) - Saindo de %s\n", numCidade, aux->nome, aux->distancia, aux->nome);
			}
			else{
				printf("Cidade %d | %s (%.2f) - Chegada em %s com %.2f km percorridos\n", numCidade, aux->nome, aux->distancia, aux->nome, kmPercorrido);
			}	
			aux = aux->proxima;
			numCidade++;
		}
	}
}

void distanciaTotal(Trajeto* trajeto){
	if(trajetoVazio(trajeto) == true || trajeto->numCidades == 1) printf("Ainda não saiu da cidade de Origem!");
	else{
		Cidade* aux = trajeto->origem;
		float kmTotal = 0.0;
	
		while(aux != NULL){
			kmTotal += aux->distancia;
			aux = aux->proxima;
		}
	
		printf("\nA distância total percorrida foi [%.2f]\n", kmTotal);
	}
}

int main(){
	Trajeto trajeto;
	inicializar(&trajeto);
	
	char cidade[50];
	float distancia = 0.0;
	int opcao = 0;
	bool validar = true;
	
	while(validar){
		printf("\n============ VIAGEM =============\n");
		printf("1) Colocar uma cidade na qual passou\n");
		printf("2) Printar as cidades na qual passou\n");
		printf("3) Printar a distância total da viagem\n");
		printf("4) Sair\n");
		printf("Digite uma opção: ");
		scanf("%d", &opcao);
		while(getchar() != '\n');
		
		switch(opcao){
			case 1: alocarCidade(&trajeto); break;
			case 2: imprimirTrajeto(&trajeto); break;
			case 3: distanciaTotal(&trajeto); break;
			case 4: validar = false; break;
			default: printf("Digite uma opção válida!"); break;
		}
		
	}
	
	return 0;
}
