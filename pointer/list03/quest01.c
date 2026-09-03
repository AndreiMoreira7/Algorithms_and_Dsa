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

void inicializar(Fila *f){
	f->inicio = NULL;
	f->fim = NULL;
}

bool filaVazia(Fila* f){
	return f->inicio == NULL;
}

void enfileirar(Fila* f, int valor){
	No* novo = (No*) malloc (sizeof(No));
	novo->dado = valor;
	novo->proximo = NULL;
	
	if(filaVazia(f)){
		f->inicio = novo;
		f->fim = novo;
	}
	else{
		f->fim->proximo = novo;
		f->fim = novo;
	}
}

void desenfileirar(Fila* f){
	if(filaVazia(f) == true)printf("N�o h� elementos para desenfileirar"); 
	else{
		No* aux = f->inicio;
		f->inicio = f->inicio->proximo;
		free(aux);
		if(f->inicio == NULL){
			f->fim = NULL;
		}
	}
}

void imprimir(Fila* f){
	if(filaVazia(f) == true)printf("n�o h� oque imprimir");
	else{
		No* atual = f->inicio;
		while(atual != NULL){	
			printf("[%d] ", atual->dado);
			atual = atual->proximo;
		}
	}
}

void obterFrente(Fila* f){
	if(filaVazia(f) == true)printf("N�o h� oque obter, a fila est� vazia");
	else printf("[%d]", f->inicio->dado);
}

void destruirFila(Fila* f){
	if(filaVazia(f) == true)printf("n�o h� oque destruir, a fila est� vazia");
	else{
		while(f->inicio != NULL){
			No* aux = f->inicio;
			f->inicio = f->inicio->proximo;
			free(aux);
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
		printf("1) Verificar se a fila est� vazia\n");
		printf("2) Enfileirar\n");
		printf("3) Desenfileirar\n");
		printf("4) Obter frente\n");
		printf("5) Imprimir lista completa\n");
		printf("6) Sair\n");
		printf("7) Destruir Fila inteira\n");
		printf("Digite a sua op��o: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1: 
				if(filaVazia(&fila) == true) printf("A fila est� vazia.");
				else printf("H� elementos na fila");
				break;
			case 2: 
				printf("Digite o valor a ser enfileirado: ");
				scanf("%d", &valor);
				enfileirar(&fila, valor);
				break;
			case 3: desenfileirar(&fila); break;
			case 4: obterFrente(&fila); break;
			case 5: imprimir(&fila); break; 
			case 6: validarLoop = false; break;
			case 7: destruirFila(&fila); break;
			default: printf("Op��o invalida, tente novamente"); break;
		}
	} 

return 0;
}
