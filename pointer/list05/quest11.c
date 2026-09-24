#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

typedef struct No{
	char caractere;
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

void empilhar(Pilha* pilha, char caractere){
	No* novo = (No*) malloc (sizeof(No));
	if(novo == NULL) {printf("ERRO AO ALOCAR MEMÓRIA!"); exit(EXIT_FAILURE);}
	
	novo->caractere = caractere;
	novo->proximo = pilha->topo;
	pilha->topo = novo;
	pilha->tamanho++;
}

void desempilhar(Pilha* pilha){
	if(pilhaVazia(pilha) == true) {printf("A pilha está vazia!"); return;}

	No* aux = pilha->topo;
	pilha->topo = pilha->topo->proximo;
	free(aux);
		
	pilha->tamanho--;
}

void imprimir(Pilha* pilha){
	if(pilhaVazia(pilha) == true) {printf("A pilha está vazia!"); return;}
	
	No* aux = pilha->topo;
	
	while(aux != NULL){
		printf("%c", aux->caractere);
		aux = aux->proximo;
	}
}

void expressaoValida(Pilha* pilha){
	if(pilhaVazia(pilha) == true) {printf("A pilha está vazia!"); return;}
	
	No* aux = pilha->topo;
	
	bool colcheteAberto = false, colcheteFechado = false;
	bool chaveAberta = false, chaveFechada = false;
	bool parenteseAberto = false, parenteseFechado = false;

	int posicaoColAberto = -1, posicaoColFechado = -1;
	int posicaoChaveAberta = -1, posicaoChaveFechada = -1;
	int posicaoParAberto = -1, posicaoParFechado = -1;
		
	bool parenteseValido = false, colcheteValido = false, chaveValida = false;
	
	int contador = 0;
	
	while(aux != NULL){
		switch(aux->caractere){
			case '[':
				colcheteAberto = !colcheteAberto;
				posicaoColAberto = contador;
				break;
			case ']':
				colcheteFechado = !colcheteFechado;
				posicaoColFechado = contador;
				break;
			case '(':
				parenteseAberto = !parenteseAberto;
				posicaoParAberto = contador;
				break;
			case ')':
				parenteseFechado = !parenteseFechado;
				posicaoParFechado = contador;
				break;
			case '{':
				chaveAberta = !chaveAberta;
				posicaoChaveAberta = contador;
				break;
			case '}':
				chaveFechada = !chaveFechada;
				posicaoChaveFechada = contador;
				break;
			default: break;		
		}
		contador++;
		aux = aux->proximo;
	}
	
	if(((chaveAberta == true) && (chaveAberta == chaveFechada) && (posicaoChaveAberta < posicaoChaveFechada)) || ((chaveAberta == true) && (chaveAberta == chaveFechada) && (posicaoChaveAberta < posicaoChaveFechada) && (posicaoChaveAberta < posicaoColAberto) && (posicaoChaveAberta < posicaoParAberto) && (posicaoChaveFechada > posicaoColFechado) && (posicaoChaveFechada > posicaoParFechado))){
		chaveValida = true;
	}
	
	if(((colcheteAberto == true) && (colcheteFechado == colcheteAberto) && (posicaoColFechado < posicaoColAberto)) || ((colcheteAberto == true) && (colcheteFechado == colcheteAberto) && (posicaoColFechado < posicaoColAberto) && (posicaoColAberto > posicaoChaveAberta) && (posicaoColAberto < posicaoParAberto) && (posicaoColFechado < posicaoChaveFechada) && (posicaoColFechado > posicaoParFechado))){
		colcheteValido = true;
	}
	
	if(((parenteseAberto == true) && (parenteseAberto == parenteseFechado) && (posicaoParAberto < posicaoParFechado)) || ((parenteseAberto == true) && (parenteseAberto == parenteseFechado) && (posicaoParAberto < posicaoParFechado) && (posicaoParAberto > posicaoChaveAberta) && (posicaoParAberto > posicaoColAberto) && (posicaoParFechado < posicaoColFechado) && (posicaoParFechado < posicaoChaveFechada))){
		parenteseValido = true;
	}

	if((chaveValida == true) || (parenteseValido == true) || (colcheteValido == true)) printf("A express�o � v�lida!");
	else printf("A expressão não é válida!");
}

int main(){
	setlocale(LC_ALL, "");
	
	Pilha pilha;
	inicializar(&pilha);
	
	int opcao = 0;
	char caractere;
	bool validarLoop = true;
	
	while(validarLoop){
		printf("\n\n========= MENU =========\n");
		printf("1) Enfileirar\n");
		printf("2) Desenfileirar\n");
		printf("3) Imprimir\n");
		printf("4) Verificar se a expressão é balanceada\n");
		printf("5) Sair\n");
		printf("Digite uma opção: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				if(pilhaVazia(&pilha)){
					printf("Digite o primeiro caractere da operação: ");
					scanf(" %c", &caractere);
				}
				else{
					printf("Digite mais um caractere da operação: ");
					scanf(" %c", &caractere);
				}
				
				empilhar(&pilha, caractere);
				break;
			case 2: desempilhar(&pilha); break;
			case 3: imprimir(&pilha); break;
			case 4: expressaoValida(&pilha); break;
			case 5: validarLoop = false; break;
			default: printf("Digite uma opção válida!"); break;
		}
	}
	
	return 0;
}
