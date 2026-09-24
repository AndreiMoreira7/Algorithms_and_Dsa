#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

typedef struct No{
	int dado;
	struct No* proximo;	
}No;

typedef struct{
	No* topo;
	int tamanho;
}Pilha;

void inicializar(Pilha* pilha){
	pilha->topo = NULL;
	pilha->tamanho = 0;
}

bool pilhaVazia(Pilha* pilha){
	return pilha->topo == NULL;
}

void empilhar(Pilha* pilha, int dado){
	No* novo = (No*) malloc (sizeof(No));
	if(novo == NULL){printf("ERRO AO ALOCAR MEMÓRIA!"); exit(EXIT_FAILURE);}
	
	novo->dado = dado;
	novo->proximo = pilha->topo;
	pilha->topo = novo;
	pilha->tamanho++;
}

void desempilhar(Pilha* pilha){
	if(pilhaVazia(pilha)) {printf("A pilha está vazia"); return;}
	
	No* aux = pilha->topo;
	pilha->topo = pilha->topo->proximo;
	free(aux);
	pilha->tamanho--;
}

void imprimir(Pilha* pilha){
	if(pilhaVazia(pilha)) {printf("A pilha está vazia"); return;}
	
	No* aux = pilha->topo;
	
	while(aux != NULL){
		printf("[%d] ", aux->dado);
		aux = aux->proximo;
	}
}

void preencherPilhas(Pilha* pilha1, Pilha* pilha2){
	printf("======== Pilha 1 ========\n");
	
	No* aux = pilha1->topo;
	int dado = 0, contador = 0;
	
	while(true){
		printf("Qual número deseja alocar na posição %d da lista 1 *Digite -1 para parar*: ", contador);
		scanf("%d", &dado);
		
		if(dado == -1){
			break;
		}
		else{
			empilhar(pilha1, dado);
			contador++;
		}
	}
	
	contador = 0;
	dado = 0;
	
	printf("\n======== Pilha 2 ========\n");
	
	while(true){
		printf("Qual número deseja alocar na posição %d da lista 2 *Digite -1 para parar*: ", contador);
		scanf("%d", &dado);
		
		if(dado == -1){
			break;
		}
		else{
			empilhar(pilha2, dado);
			contador++;
	}
}
}

void multiplexar(Pilha* pilha1, Pilha* pilha2, Pilha* resultante){
	if(pilhaVazia(pilha1) && pilhaVazia(pilha2)) {printf("As pilhas estão vazias"); return;}
	
	No* aux1 = pilha1->topo;
	No* aux2 = pilha2->topo;
	
	while(aux1 != NULL || aux2 != NULL){
		if(aux1 != NULL){
			empilhar(resultante, aux1->dado);
			aux1 = aux1->proximo;
		}
		
		if(aux2 != NULL){
			empilhar(resultante, aux2->dado);
			aux2 = aux2->proximo;
		}
	}
}

int main(){
	setlocale(LC_ALL, "");
	
	Pilha pilha1, pilha2, resultante;
	inicializar(&pilha1);
	inicializar(&pilha2);
	inicializar(&resultante);
	
	preencherPilhas(&pilha1, &pilha2);
	multiplexar(&pilha1, &pilha2, &resultante);
	printf("\nPILHA RESULTANTE: ");
	imprimir(&resultante);
	
	return 0;
}
