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
	if(novo == NULL) {printf("ERRO AO ALOCAR MEMÓRIA!"); exit(EXIT_FAILURE);}
	
	novo->dado = dado;
	novo->proximo = pilha->topo;
	pilha->topo = novo;
	pilha->tamanho++;
	
	printf("Elemento alocado com sucesso!");
}

void desempilhar(Pilha* pilha){
	if(pilhaVazia(pilha)) printf("A pilha está vazia!");
	else{
		No* aux = pilha->topo;
		pilha->topo = pilha->topo->proximo;
		free(aux);
		
		pilha->tamanho--;	
	}
}

void imprimir(Pilha* pilha){
	if(pilhaVazia(pilha)) {printf("A pilha está vazia!"); return;}
	
	No* aux = pilha->topo;
	
	while(aux != NULL){
		printf("[%d] ", aux->dado);
		aux = aux->proximo;
	}
}

void saoIguais(Pilha* pilha1, Pilha* pilha2){
	if(pilhaVazia(pilha1)) printf("A pilha 1 está vazia!");
	else if(pilhaVazia(pilha2)) printf("A pilha 2 está vazia!"); 
	
	else{
		No* aux1 = pilha1->topo;
		No* aux2 = pilha2->topo;
	
		while(aux1 != NULL && aux2 != NULL){
			if(aux2->dado != aux1->dado){
				printf("As pilhas não são iguais!");
				return;
			}
		
			aux2 = aux2->proximo;
			aux1 = aux1->proximo;
		}
		printf("As pilhas são iguais!");
	}
}

int main(){
	setlocale(LC_ALL, "");
	
	Pilha pilha1, pilha2;
	inicializar(&pilha1);
	inicializar(&pilha2);
	
	int escolherPilha = 0, opcao = 0, dado = 0;
	bool validarLoop = true;
	
	printf("ESCOLHA A PILHA [1 - 2]: ");
	scanf("%d", &escolherPilha);
	
	bool loopInterno1 = true, loopInterno2 = true;
	
	while(true){	
		loopInterno1 = true;
		loopInterno2 = true;
		
		if(escolherPilha == 1){
			while(loopInterno1 == true){
				printf("\n\n====== PILHA 1 ======\n");
				printf("1) Empilhar\n");
				printf("2) Desempilhar\n");
				printf("3) Imprimir\n");
				printf("4) Comparar com a segunda pilha\n");
				printf("5) Ir para a pilha 2\n");
				printf("6) Sair do programa\n");
				printf("Digite uma opção: ");
				scanf("%d", &opcao);
			
				switch(opcao){
					case 1:
						printf("Digite o número que deseja alocar: ");
						scanf("%d", &dado);
					
						empilhar(&pilha1, dado);
						break;
					case 2: desempilhar(&pilha1); break;
					case 3: imprimir(&pilha1); break;
					case 4: saoIguais(&pilha1, &pilha2); break;
					case 5: loopInterno1 = false; break;
					case 6: exit(EXIT_FAILURE);
					default: printf("Digite uma opção válida!"); break;  
				}
			}
			
			if(validarLoop) escolherPilha = 2;
		}
		
		else if(escolherPilha == 2){
			while(loopInterno2 == true){
				printf("\n\n====== PILHA 2 ======\n");
				printf("1) Empilhar\n");
				printf("2) Desempilhar\n");
				printf("3) Imprimir\n");
				printf("4) Comparar com a segunda pilha\n");
				printf("5) Ir para a pilha 1\n");
				printf("6) Sair do programa\n");
				printf("Digite uma opção: ");
				scanf("%d", &opcao);
			
				switch(opcao){
					case 1:
						printf("Digite o número que deseja alocar: ");
						scanf("%d", &dado);
					
						empilhar(&pilha2, dado);
						break;
					case 2: desempilhar(&pilha2); break;
					case 3: imprimir(&pilha2); break;
					case 4: saoIguais(&pilha1, &pilha2); break;
					case 5: loopInterno2 = false; break;
					case 6: exit(EXIT_FAILURE);
					default: printf("Digite uma opção válida!"); break;  
				}
			}
			
			if(validarLoop) escolherPilha = 1;
		}
		
		else{
			printf("Opção inválida! Estamos escerrando o programa!");
			exit(EXIT_FAILURE);
		}
	}
	
	return 0;
}
