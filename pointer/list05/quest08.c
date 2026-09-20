#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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
	if(novo == NULL){ printf("Erro ao alocar memória!"); exit(EXIT_FAILURE);}
	
	novo->dado = dado;
	novo->proximo = pilha->topo;
	pilha->topo = novo;
	pilha->tamanho++;
	
	printf("Elemento alocado com sucesso!");
}

void desempilhar(Pilha* pilha){
	if(pilhaVazia(pilha) == true) printf("A pilha está vazia");
	else{
		No* aux = pilha->topo;
		pilha->topo = pilha->topo->proximo;
		free(aux);
		pilha->tamanho--;
		
		printf("Elemento excluido com sucesso!");
	}
}

void imprimir(Pilha* pilha){
	if(pilhaVazia(pilha) == true) printf("A pilha está vazia!");
	else{
		No* aux = pilha->topo;
		
		while(aux != NULL){
			printf("[%d] ", aux->dado);
			aux = aux->proximo;
		}
	}
}

void mediaDosNumeros(Pilha* pilha){
	if(pilhaVazia(pilha) == true) printf("A pilha está vazia!");
	else{
		No* aux = pilha->topo;
		int media = 0;
		
		while(aux != NULL){
			media += aux->dado;
			aux = aux->proximo;
		}
		
		media /= pilha->tamanho;
		
		printf("A média dos elementos é [%d]", media);
	}
}

int main(){
	setlocale(LC_ALL, "");
	
	Pilha pilha;
	inicializar(&pilha);
	
	int opcao = 0, dado = 0;
	bool validarLoop = true;
	
	while(validarLoop){
		printf("\n\n======= MENU =======\n");
		printf("1) Verificar se a pilha está vazia\n");
		printf("2) Empilhar\n");
		printf("3) Desempilhar\n");
		printf("4) Imprimir\n");
		printf("5) Média dos números\n");
		printf("6) Sair\n");
		printf("Digite uma opção: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1: 
				if(pilhaVazia(&pilha) == true) printf("A pilha está vazia!");
				else printf("Há elementos na pilha!"); break;
			case 2: 
				printf("Digite o número que deseja empilhar: ");
				scanf("%d", &dado);
				
				empilhar(&pilha, dado);
				break;
			case 3: desempilhar(&pilha); break;
			case 4: imprimir(&pilha); break;
			case 5: mediaDosNumeros(&pilha); break;
			case 6: validarLoop = false; break;
			default: printf("Opção inválida, tente novamente!"); break;
		}
	}
	
	return 0;
}
