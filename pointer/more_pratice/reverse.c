//Escreva uma função que inverte uma lista encadeada alterando apenas os ponteiros (sem criar novos nós ou copiar dados).

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct No{
	int dado;
	struct No* proximo;	
}No;

typedef struct{
	No* inicio;
	No* fim;
}Fila;

void inicializar(Fila* f){
	f->inicio = NULL;
	f->fim = NULL;
}

bool filaVazia(Fila* f){
	return f->inicio == NULL;
}

void enfileirar(Fila* f, int dado){
	No* novo = (No*) malloc (sizeof(No));
	if(novo == NULL){printf("Erro ao alocar memória!"); exit(EXIT_FAILURE);}
	
	novo->dado = dado;
	novo->proximo = NULL;
	
	if(filaVazia(f) == true){
		f->inicio = novo;
		f->fim = novo;
	}
	else{
		f->fim->proximo = novo;
		f->fim = novo;
	}
}

void inverter(Fila* f){ //função pedida
	No* anterior = NULL;
	No* atual = f->inicio;
	No* posterior = NULL;
	
	while(atual != NULL){
		posterior = atual->proximo;
		atual->proximo = anterior;
		anterior = atual;
		atual = posterior;
	}
	
	No* temp = f->inicio;
	f->inicio = f->fim;
	f->fim = temp;
}

void imprimir(Fila* f){
	if(filaVazia(f) == true) printf("A fila está vazia!");
	else{
		No* aux = f->inicio;
		
		while(aux != NULL){
			printf("[%d] ", aux->dado);
			aux = aux->proximo;
		}
	}
}

int main(){
	Fila fila;
	inicializar(&fila);
	int valor = 0, opcao = 0;	
	bool validarLoop = true;
	
	while(validarLoop == true){
		printf("\n\n========= Menu =========\n");
		printf("1) Enfileirar\n");
		printf("2) Inverter\n");
		printf("3) Imprimir lista completa\n");
		printf("4) Sair\n");
		printf("Digite a sua opção: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1: 
				printf("Digite um número: ");
				scanf("%d", &valor);
				
				enfileirar(&fila, valor);
				break;
			case 2: inverter(&fila); break;
			case 3: imprimir(&fila); break; 
			case 4: validarLoop = false; break;
			default: printf("Opção invalida, tente novamente"); break;
		}
	} 
	
	
	
}
