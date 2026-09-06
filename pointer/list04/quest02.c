#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct No{
	int idade;
	int senha;
	char nome[50];
	char pcdOuGest[10];
	struct No* proximo;		
}No;

typedef struct{
	No* inicio;
	No* fim;
	int tamanho;
}Fila;

void limparQuebraLinha(char* str){
	str[strcspn(str, "\n")] = '\0';
}

void converterMinuscula(char *str){
	while(*str){
		*str = tolower(*str);
		str++;
	}
}

void inicializar(Fila* fila){
	fila->inicio = NULL;
	fila->fim = NULL;
	fila->tamanho = 0;
}

bool filaVazia(Fila* fila){
	return fila->inicio == NULL;
}

void enfileirar(Fila* fila, int idade, char nome[], char pcdOuGest[], int senha){
	No* novo = (No*) malloc (sizeof(No));
	if(novo == NULL){printf("Erro ao alocar memória!"); exit(EXIT_FAILURE);}
	
	novo->idade = idade;
	novo->senha = senha;
	strcpy(novo->nome, nome);
	strcpy(novo->pcdOuGest, pcdOuGest);
	novo->proximo = NULL;
	
	if(filaVazia(fila) == true){
		fila->inicio = novo;
		fila->fim = novo;
	}
	else{
		fila->fim->proximo = novo;
		fila->fim = novo;
	}
	fila->tamanho++;
}

void alocarNaFila(Fila* n, Fila* p, Fila* pp){
	int idade = 0;
	char nome[50], pcdOuGest[10];
	
	printf("Digite o nome do cliente: ");
	fgets(nome, sizeof(nome), stdin);
	limparQuebraLinha(nome);
	
	printf("Digite a idade do cliente: ");
	scanf("%d", &idade);
	while(getchar() != '\n');
	
	printf("O cliente é PCD ou Gestante? [sim] ou  [não]: ");
	fgets(pcdOuGest, sizeof(pcdOuGest), stdin);
	limparQuebraLinha(pcdOuGest);
	converterMinuscula(pcdOuGest);
		
	
	if(idade >= 80){
		enfileirar(pp, idade, nome, pcdOuGest, pp->tamanho + 1);
		printf("Cliente alocado na fila de prioridade da prioridade!");
	}
	else if((idade >= 60 && idade < 80) || strcmp(pcdOuGest, "sim") == 0){
		enfileirar(p, idade, nome, pcdOuGest, p->tamanho + 1);
		printf("Cliente alocado na fila de prioridade!");
	}
	else{
		enfileirar(n, idade, nome, pcdOuGest, n->tamanho + 1);
		printf("Cliente alocado na fila normal!");		
	}
}

void imprimir(Fila* fila){
	if(filaVazia(fila) == true) printf("A fila está vazia!\n");
	else{
		No* aux = fila->inicio;
		while(aux != NULL){
			printf("Nome: %s | idade: %d | É pcd ou gestante?: %s | Senha: %d\n", aux->nome, aux->idade, aux->pcdOuGest, aux->senha);
			aux = aux->proximo;
		}
	}
}

void ordemFilas(Fila* n, Fila* p, Fila* pp){
	printf("\n========= Fila Normal =========\n");
	imprimir(n);
	
	printf("\n========= Fila prioridade =========\n");
	imprimir(p);
	
	printf("\n========= Fila prioridade da prioridade =========\n");
	imprimir(pp);
}

void ordemChamada(Fila* c, Fila* n, Fila* p, Fila* pp){
	if(filaVazia(n) == true && filaVazia(p) == true && filaVazia(pp) == true) printf("Todas as filas estão vazias!");
	else{
	No* auxpp = pp->inicio;
	No* auxn = n->inicio;
	No* auxp = p->inicio; 
	
	while(auxn != NULL || auxpp != NULL || auxp != NULL){
			if(auxpp != NULL){
				enfileirar(c, auxpp->idade, auxpp->nome, auxpp->pcdOuGest, c->tamanho + 1);
				auxpp = auxpp->proximo;
			}
			
			for(int i = 0; i < 2 && auxp != NULL; i++){
				enfileirar(c, auxp->idade, auxp->nome, auxp->pcdOuGest, c->tamanho + 1);
				auxp = auxp->proximo;
			}  
			
			if(auxn != NULL){
				enfileirar(c, auxn->idade, auxn->nome, auxn->pcdOuGest, c->tamanho + 1);
				auxn = auxn->proximo;
			}  
 	}
}

void imprimirOrdem(Fila* c, Fila* n, Fila* p, Fila* pp){
	printf("\n========== Ordem de chamada para atendimento ==========\n");
	ordemChamada(c, n, p, pp);
	imprimir(c);
}

int main(){
	Fila normal, prioridade, maisPrioridade, chamada;
	
	inicializar(&normal);
	inicializar(&prioridade);
	inicializar(&maisPrioridade);
	inicializar(&chamada);
	
	int opcao = 0;
	bool validarLoop = true;
	
	while(validarLoop){
		printf("\n\n========== Fila Bancária ==========\n");
		printf("1) Alocar cliente na fila\n");
		printf("2) Imprimir filas\n");
		printf("3) Imprimir ordem de chamada\n");
		printf("4) Sair\n");
		printf("Escolha uma opção: ");
		scanf("%d", &opcao);
		while(getchar() != '\n');
		
		switch(opcao){
			case 1: alocarNaFila(&normal, &prioridade, &maisPrioridade); break;
			case 2: ordemFilas(&normal, &prioridade, &maisPrioridade); break;
			case 3: imprimirOrdem(&chamada, &normal, &prioridade, &maisPrioridade); break;
			case 4: validarLoop = false; break;
			default: printf("Opção inválida, tente novamente!");
		}
	}
	
	return 0;
}
