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

void consultarTopo(Pilha* pilha){
	if(pilhaVazia(pilha) == true) printf("A pilha está vazia!");
	else{
		printf("O elemento do topo é [%d]", pilha->topo->dado);
	}
}

void quantidadeElementos(Pilha* pilha){
	printf("A quantidade de elementos é [%d]", pilha->tamanho);
}

void pilhaInvertida(Pilha* pilha){
	if(pilhaVazia(pilha) == true) printf("A fila está vazia!");
	else{
		No* aux = pilha->topo;
		Pilha* invertida;
		inicializar(invertida);
		
		while(aux != NULL){
			empilhar(invertida, aux->dado);
			aux = aux->proximo;
		}
		
		printf("Pilha Normal: ");
		imprimir(pilha);
		printf("\nPilha invertida: ");
		imprimir(invertida);
	}
}

void esvaziarPilha(Pilha* pilha){
	if(pilhaVazia(pilha) == true) printf("A pilha já está vazia!");
	else{
		No* aux;
		
		for(int i = 0; i < pilha->tamanho; i++){
			aux = pilha->topo; 
			pilha->topo = pilha->topo->proximo;
			free(aux);
			pilha->tamanho--;
		}	
		printf("Pilha Deletada com sucesso!");
	}
}

void menorValor(Pilha* pilha){
	if(pilhaVazia(pilha) == true) printf("A lista está vazia!");
	else{
		int menor = pilha->topo->dado;
		No* aux = pilha->topo;
		
		for(int i = 0; i < pilha->tamanho; i++){
			if(menor > aux->dado){
				menor = aux->dado;
			}
			aux = aux->proximo;
		}
		printf("O menor número é [%d]", menor);
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
		printf("5) Consultar Topo\n");
		printf("6) Imprimir quantidade de elementos\n");
		printf("7) Inverter Fila\n");
		printf("8) Esvaziar pilha\n");
		printf("9) Menor valor\n");
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
			case 5: consultarTopo(&pilha); break;
			case 6: quantidadeElementos(&pilha); break;
			case 7: pilhaInvertida(&pilha); break;
			case 8: esvaziarPilha(&pilha); break;
			case 9: menorValor(&pilha); break;
			default: printf("Digite uma opção válida!"); break;
		}
	}
	
	return 0;
}
