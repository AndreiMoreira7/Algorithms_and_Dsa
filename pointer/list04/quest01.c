#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No{
	int dado;	
	struct No* proximo;
}No;

typedef struct{
	int id;
	No* inicio;
	No* fim;
}Fluxo;

typedef struct NoCanal{
	int id;
	int dado;
	struct NoCanal* proximo;
}NoCanal;

typedef struct{
	NoCanal* inicio;
	NoCanal* fim;
}Canal;

void inicializarFluxo(Fluxo* f, int id){
	f->id = id;
	f->inicio = NULL;
	f->fim = NULL;
}

void enfileirarFluxo(Fluxo* f, int dado){
	No* novo = (No*) malloc (sizeof(No));
	if(novo == NULL){ printf("Erro ao alocar memória!"); exit(EXIT_FAILURE);}
	
	novo->dado = dado;
	novo->proximo = NULL;
	
	if(f->inicio == NULL){
		f->inicio = novo;
		f->fim = novo;
		printf("Primeiro Nó alocado com sucesso!\n");
	}
	else{
		f->fim->proximo = novo;
		f->fim = novo;
		printf("Mais um Nó alocado com sucesso!\n");
	}
}

void lerDados(Fluxo* f){
	printf("\n======== Digite os dados do Fluxo %d ========\n", f->id);
	
	bool parar = false;
	int i = 0, valor = 0;
	
	while(!parar){
		printf("\nDigite o valor que ficará no Nó %d do Fluxo %d: ", i, f->id);
		scanf("%d", &valor);
		
		if(valor != -1){
			enfileirarFluxo(f, valor);
			i++;
		}
		else parar = true;
	}	
}

void imprimirFluxo(Fluxo* f){
	if(f->inicio == NULL) printf("O fluxo %d está vazio!\n", f->id);
	else{
		printf("\n\n======== Fluxo %d ========\n", f->id);
		No* atual = f->inicio;
		while(atual != NULL){
			printf("[%d ]", atual->dado);
			atual = atual->proximo;
		}
	}
}

void inicializarCanal(Canal* c){
	c->inicio = NULL;
	c->fim = NULL;
}

void desenfileirarFluxo(Fluxo* f){
	if(f->inicio == NULL) printf("O fluxo %d está vazio, não há oque desenfileirar!", f->id);
	else{
		No* aux = f->inicio;
		f->inicio = f->inicio->proximo;
		free(aux);
		if(f->inicio == NULL) f->fim = NULL;
	}
}

void enfileirarCanal(Canal* c, int id, int dado){
	NoCanal* novo = (NoCanal*) malloc (sizeof(NoCanal));
	if(novo == NULL) {printf("Falha ao alocar memória!"); exit(EXIT_FAILURE);}
	
	novo->dado = dado;
	novo->id = id;
	novo->proximo = NULL;
	
	if(c->inicio == NULL){
		c->inicio = novo;
		c->fim = novo;
	}
	else{
		c->fim->proximo = novo;
		c->fim = novo;
	}
}

void multiplexar(Canal* c, Fluxo* f1, Fluxo* f2, Fluxo* f3){
	while(f1->inicio != NULL || f2->inicio != NULL || f3->inicio != NULL){
		if(f1->inicio != NULL){
			enfileirarCanal(c, f1->id, f1->inicio->dado);
			desenfileirarFluxo(f1);
		}
		if(f2->inicio != NULL){
			enfileirarCanal(c, f2->id, f2->inicio->dado);
			desenfileirarFluxo(f2);
		}	
		if(f3->inicio != NULL){
			enfileirarCanal(c, f3->id, f3->inicio->dado);
			desenfileirarFluxo(f3);
		}					
	}
}

void imprimirEDesenfileirar(Canal* c){
	printf("\n\n============ Canal Compartilhado =============\n");
	
	bool parar = false;
	
	while(!parar){
		NoCanal* aux = c->inicio;
		
		if(aux != NULL){
			printf("ID: %d | Dado: %d\n", aux->id, aux->dado);
			c->inicio = c->inicio->proximo;
			free(aux);
		}
		else parar = true;
	}
}

int main(){
	Fluxo f1, f2, f3;
	Canal canal;
	
	inicializarFluxo(&f1, 1);
	inicializarFluxo(&f2, 2);
	inicializarFluxo(&f3, 3);
	inicializarCanal(&canal);
	
	lerDados(&f1);
	lerDados(&f2);
	lerDados(&f3);
	
	imprimirFluxo(&f1);
	imprimirFluxo(&f2);
	imprimirFluxo(&f3);
	
	multiplexar(&canal, &f1, &f2, &f3);
	
	imprimirEDesenfileirar(&canal);
	
	return 0;
}
