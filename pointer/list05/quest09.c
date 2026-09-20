#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No{
	char letra;
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

void empilharLetra(Pilha* pilha, char letra){
	No* novo = (No*) malloc (sizeof(No));
	if(novo == NULL) {printf("Erro ao alocar memória!"); exit(EXIT_FAILURE);}
	
	novo->letra = letra;
	novo->proximo = pilha->topo;
	pilha->topo = novo;
	pilha->tamanho++;
}

void desempilharLetra(Pilha* pilha){
	if(pilhaVazia(pilha) == true) printf("A pilha está vazia!");
	else{
		No* aux = pilha->topo;
		pilha->topo = pilha->topo->proximo;
		free(aux);
		pilha->tamanho--;
	}
}

void imprimir(Pilha* pilha){
	if(pilhaVazia(pilha) == true) printf("A pilha está vazia!");
	else{
		No* aux = pilha->topo;
		
		while(aux != NULL){
			printf("%c", aux->letra);
			aux = aux->proximo;
		}
	}
}

void inverterString(Pilha* pilha){
	if(pilhaVazia(pilha) == true) printf("A pilha está vazia!");
	else{
		No* aux = pilha->topo;
		
		Pilha* pilhaAux;
		inicializar(pilhaAux);
		
		while(aux != NULL){
			empilharLetra(pilhaAux, aux->letra);
			aux = aux->proximo;
		}
		
		printf("String normal: ");
		imprimir(pilha);
		
		printf("\nString invertida: ");
		imprimir(pilhaAux);
	}
}

int main(){
	setlocale(LC_ALL, "");
	
	Pilha pilha;
	inicializar(&pilha);
	
	int opcao = 0;
	char letra;
	bool validarLoop = true;
	
	while(validarLoop){
		printf("\n\n======= MENU =======\n");
		printf("1) Verificar se a pilha está vazia\n");
		printf("2) Empilhar letra\n");
		printf("3) Desempilhar letra\n");
		printf("4) Imprimir String\n");
		printf("5) Inverter String\n");
		printf("6) Sair\n");
		printf("Digite uma opção: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1: 
				if(pilhaVazia(&pilha) == true) printf("A pilha está vazia!");
				else printf("Há elementos na pilha!"); break;
			case 2: 
				printf("Digite o caractere que deseja empilhar: ");
				scanf(" %c", &letra);
				
				empilharLetra(&pilha, letra);
				break;
			case 3: desempilharLetra(&pilha); break;
			case 4: imprimir(&pilha); break;
			case 5: inverterString(&pilha); break;
			case 6: validarLoop = false; break;
			default: printf("Opção inválida, tente novamente!"); break;
		}
	}
	
	return 0;
}
