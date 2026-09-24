#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No{
	int dado;
	struct No* proximo;
}No;

typedef struct{
	int tamanho;
	No* topo;
}Pilha;

void inicializar(Pilha* pilha){
	pilha->tamanho = 0;
	pilha->topo = NULL;
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
}

void desempilhar(Pilha* pilha){
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
			printf("[%d] ", aux->dado);
			aux = aux->proximo;
		}
	}
}

void esvaziarPilha(Pilha* pilha){
	if(pilhaVazia(pilha)) printf("A pilha está vazia!");
	else{		
		while(!pilhaVazia(pilha)){
			No* aux = pilha->topo;
			pilha->topo = pilha->topo->proximo;
			free(aux);
			
			pilha->tamanho--;
		}
	}
}

void separarParImpar(Pilha* pilha, Pilha* par, Pilha* impar){
	if(pilhaVazia(pilha)) printf("\nA pilha está vazia!");
	else{
		No* aux = pilha->topo;
		
		while(aux != NULL){
			if(aux->dado % 2 == 0){
				empilhar(par, aux->dado);
			}
			else{
				empilhar(impar, aux->dado);
			}
			
			aux = aux->proximo;
		}
	}
}

void printarParImpar(Pilha* par, Pilha* impar){
	No* aux;
	
	if(pilhaVazia(par)) printf("Não existe números pares na pilha!");
	else{
		printf("\nNúmeros pares: ");
		aux = par->topo;
		
		while(aux != NULL){
			printf("[%d] ", aux->dado);
			aux = aux->proximo;
		}
	}
	
	if(pilhaVazia(impar)) printf("\nNão existe números impares na Pilha!");
	else{
		printf("\nNúmeros impares: ");
		aux = impar->topo;
		
		while(aux != NULL){
			printf("[%d] ", aux->dado);
			aux = aux->proximo;
		}
	}
	
	esvaziarPilha(par);
	esvaziarPilha(impar);
}
	
int main(){
	setlocale(LC_ALL, "");
	
	Pilha pilha, par, impar;
	inicializar(&pilha);
	inicializar(&par);
	inicializar(&impar);
	
	int opcao = 0, dado = 0;
	bool validarLoop = true;
	
	while(validarLoop){
		printf("\n\n======= MENU =======\n");
		printf("1) Verificar se a pilha está vazia\n");
		printf("2) Empilhar\n");
		printf("3) Desempilhar\n");
		printf("4) Imprimir\n");
		printf("5) Números pares e impares na pilha\n");
		printf("6) EsvaziarPilha\n");
		printf("7) Sair\n");
		printf("Digite uma opção: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				if(pilhaVazia(&pilha) == true) printf("A pilha está vazia!");
				else printf("Há elementos na pilha!");
				break;
			case 2:
				printf("Digite o elemento que deseja empilhar: ");
				scanf("%d", &dado);
				
				empilhar(&pilha, dado);
				break;
			case 3: desempilhar(&pilha); break;
			case 4: imprimir(&pilha); break;
			case 5: 
				separarParImpar(&pilha, &par, &impar);
				printarParImpar(&par, &impar);
				break;
			case 6: esvaziarPilha(&pilha);
			case 7: validarLoop = false; break;
			default: printf("Digite uma opção válida!"); break;
		}
	}
	
	return 0;
}

