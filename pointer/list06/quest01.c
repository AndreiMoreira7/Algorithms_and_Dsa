#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No{
	int valor;
	struct No* proximo;
}No;

typedef struct{
	No* inicio;
	No* fim;
	int tamanho;	
}Lista;

void inicializar(Lista* lista){
	lista->inicio = NULL;
	lista->fim = NULL;
	lista->tamanho = 0;
}

bool listaVazia(Lista* lista){
	return lista->inicio == NULL;
}

void inserirOrdenado(Lista* lista){
	No* novo = (No*) malloc(sizeof(No));
	if(novo == NULL){ printf("ERRO AO ALOCAR MEMÓRIA"); exit(EXIT_FAILURE);}

	int valor;
	printf("Digite o Elemento que deseja colocar na lista: ");
	scanf("%d", &valor);

	novo->valor = valor;
	novo->proximo = NULL;
	
	if(listaVazia(lista) || lista->inicio->valor >= valor){
		novo->proximo = lista->inicio;
		lista->inicio = novo;
		
		if(lista->fim == NULL) lista->fim = novo;
	}
	else{
		No* atual = lista->inicio;
		
		while(atual->proximo != NULL && atual->proximo->valor < valor){
			atual = atual->proximo;
		}
		
		novo->proximo = atual->proximo;
		atual->proximo = novo;
		
		if(novo->proximo == NULL) lista->fim = novo;
	}
	
	lista->tamanho++;
}

void remover(Lista* lista){
	if(listaVazia(lista)) {printf("A lista está vazia"); return;}
	
	int valor;
	printf("Digite o elemento que deseja remover: ");
	scanf("%d", &valor);
	
	No* temp;
	
	if(lista->inicio->valor == valor){
		temp = lista->inicio;
		lista->inicio = lista->inicio->proximo;
		
		if(lista->inicio == NULL) lista->fim = NULL;
		
		free(temp);
	}
	
	else{
		No* atual = lista->inicio;
		
		while(atual->proximo != NULL && atual->proximo->valor < valor) atual = atual->proximo;
		
		if(atual->proximo != NULL && atual->proximo->valor == valor){
			temp = atual->proximo;
			atual->proximo = temp->proximo;
			
			if(atual->proximo == NULL) lista->fim = atual;
			
			free(temp);
		}
		
		else{
			printf("Elemento não encontrado!");
			return;
		}			
	}
	
	lista->tamanho--;
}

void quantidadeElementos(Lista* lista){
	printf("A quantidade de elementos na lista é [%d]", lista->tamanho);
}

void verificarElemento(Lista* lista){
	if(listaVazia(lista)){printf("A lista está vazia!"); return;}
	
	int elemento;
	
	printf("Digite o elemento que quer verificar se existe na lista: ");
	scanf("%d", &elemento);
	
	No* aux = lista->inicio;
	int posicao = 0;
	
	while(aux != NULL){
		if(aux->valor == elemento){
			printf("O elemento [%d] foi encontrado na posição [%d]", elemento, posicao);
			return;
		}
		
		if(aux->valor > elemento) break;
		
		aux = aux->proximo;
		posicao++;
	}
	
	printf("O elemento [%d] não foi encontrado na lista!", elemento);
}

void liberarLista(Lista* lista){
	if(listaVazia(lista)){printf("A lista está vazia!"); return;}
	
	No* aux;
	int tamanho = lista->tamanho;
	
	for(int i = 0; i < tamanho; i++){
		aux = lista->inicio;
		lista->inicio = lista->inicio->proximo;
		free(aux);
	}
	
	printf("Lista liberada com sucesso!");
	
	inicializar(lista);
}

void imprimir(Lista* lista){
	if(listaVazia(lista)){printf("A lista está vazia!"); return;}
	
	No* aux = lista->inicio;
	
	while(aux != NULL){
		printf("[%d]", aux->valor);
		aux = aux->proximo;
	}
}

int main(){
	setlocale(LC_ALL, "");
	
	Lista lista;
	inicializar(&lista);
	
	int opcao = 0; int valor = 0;
	bool validar = true;
	
	while(validar){
		printf("\n\n====== MENU ======\n");
		printf("1) Adicionar Elemento\n");
		printf("2) Retirar elemento\n");
		printf("3) Imprimir\n");
		printf("4) Verificar se a lista está vazia\n");
		printf("5) Buscar elemento na lista\n");
		printf("6) liberar Lista\n");
		printf("7) Quantidade de elementos na lista\n");
		printf("8) Sair\n");
		printf("Digite uma opção: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1: inserirOrdenado(&lista); break;
			case 2: remover(&lista); break;
			case 3: imprimir(&lista); break;
			case 4:
				if(listaVazia(&lista)) printf("A lista está vazia!");
				else printf("Há elementos na lista!");
				break;
			case 5: verificarElemento(&lista); break;
			case 6: liberarLista(&lista); break;
			case 7: quantidadeElementos(&lista); break;
			case 8: 
				liberarLista(&lista);
				validar = false; 
				break;
			default: printf("Opção inválida, tente novamente!"); break;
		}
	}
	
	return 0;
}
