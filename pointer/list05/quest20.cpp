#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

#define QUANT_DISCOS 6

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

void imprimir(Pilha* pilha1, Pilha* pilha2, Pilha* pilha3){
	No* aux;
	
	printf("\nPILHA 1: ");
	if(pilhaVazia(pilha1) == true) printf("======");
	else{
		aux = pilha1->topo;
		
		while(aux != NULL){
			printf("[%d] ", aux->dado);
			aux = aux->proximo;
		}
	}
	
	printf("\nPILHA 2: ");
	if(pilhaVazia(pilha2) == true) printf("======");
	else{
		aux = pilha2->topo;
		
		while(aux != NULL){
			printf("[%d] ", aux->dado);
			aux = aux->proximo;
		}
	}
	
	printf("\nPILHA 3: ");
	if(pilhaVazia(pilha3) == true) printf("======");
	else{
		aux = pilha3->topo;
		
		while(aux != NULL){
			printf("[%d] ", aux->dado);
			aux = aux->proximo;
		}
	}
}

void moverElemento(Pilha* pilha1, Pilha* pilha2, Pilha* pilha3){
	int mover = 0, movido = 0;
	
	printf("Escolha de qual pilha quer mover o elemento: ");
	scanf("%d", &mover);
	printf("Escolha qual a pilha que vai receber o elemento: ");
	scanf("%d", &movido);
	
	switch(mover){
		case 1:
			if(!pilhaVazia(pilha1)){
				if(movido == 2 ){
					if(pilha2->topo == NULL || pilha1->topo->dado < pilha2->topo->dado){
						empilhar(pilha2, pilha1->topo->dado);
						desempilhar(pilha1);
					}
					else{
						printf("Não da para colocar elemento maior em cima de um menor!");
					}
				}
				else if(movido == 3){
					if(pilha3->topo == NULL || pilha1->topo->dado < pilha3->topo->dado){
						empilhar(pilha3, pilha1->topo->dado);
						desempilhar(pilha1);
					}
					else{
						printf("Não da para colocar elemento maior em cima de menor!");
					}
				}
				else{
					printf("Não da para empilhar!");
				}
			}
			else{
				printf("A pilha está vazia!");
			}
			break;
		case 2:
			if(!pilhaVazia(pilha2)){
				if(movido == 1){
					if(pilha1->topo == NULL || pilha2->topo->dado < pilha1->topo->dado){
						empilhar(pilha1, pilha2->topo->dado);
						desempilhar(pilha2);
					}
					else{
						printf("Não da para colocar elemento maior em cima de um menor!");
					}
				}
				else if(movido == 3){
					if(pilha3->topo == NULL || pilha2->topo->dado < pilha3->topo->dado){
						empilhar(pilha3, pilha2->topo->dado);
						desempilhar(pilha2);
					}
					else{
						printf("Não da para colocar elemento maior em cima de menor!");
					}
				}
				else{
					printf("Não da para empilhar!");
				}
			}
			else{
				printf("A pilha está vazia!");
			}
			break;
		case 3:
			if(!pilhaVazia(pilha3)){
				if(movido == 2){
					if(pilha2->topo == NULL || pilha3->topo->dado < pilha2->topo->dado){
						empilhar(pilha2, pilha3->topo->dado);
						desempilhar(pilha3);
					}
					else{
						printf("Não da para colocar elemento maior em cima de um menor!");
					}
				}
				else if(movido == 1){
					if(pilha1->topo == NULL || pilha3->topo->dado < pilha1->topo->dado){
						empilhar(pilha1, pilha3->topo->dado);
						desempilhar(pilha3);
					}
					else{
						printf("Não da para colocar elemento maior em cima de menor!");
					}
				}
				else{
					printf("Não da para empilhar!");
				}
			}
			else{
				printf("A pilha está vazia!");
			}
			break;
		default: printf("Não existe essa pilha!"); break;
	}
}

void limparPilha(Pilha* pilha){
	while(!pilhaVazia(pilha)){
		desempilhar(pilha);
	}
}
	
int main(){
	setlocale(LC_ALL, "");
	
	Pilha pilha1, pilha2, pilha3;
	inicializar(&pilha1);
	inicializar(&pilha2);
	inicializar(&pilha3);
	
	for(int i = QUANT_DISCOS; i > 0; i--) empilhar(&pilha1, i);
	
	int opcao = 0;
	bool validarLoop = true;
	
	while(validarLoop){
		printf("\n======= TORRE DE HANOI =======\n");
		imprimir(&pilha1, &pilha2, &pilha3);
		
		if(pilha2.tamanho == QUANT_DISCOS || pilha3.tamanho == QUANT_DISCOS){
			printf("Você Ganhou!!!");
			break;
		}
		
		printf("\n\n1) Mover elemento\n");
		printf("2) Sair\n");
		printf("Digite uma opção: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1: moverElemento(&pilha1,&pilha2, &pilha3); break;
			case 2: validarLoop = false; break;
			default: printf("Digite uma opçãoo válida!"); break;
		}
	}
	
	limparPilha(&pilha1);
	limparPilha(&pilha2);
	limparPilha(&pilha3);
	
	return 0;
}