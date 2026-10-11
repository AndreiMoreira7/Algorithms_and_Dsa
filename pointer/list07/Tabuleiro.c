#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define BUFFER 30

typedef struct Casa{
	int posicao;
	struct Casa* proximo;
	struct Casa* anterior;
}Casa;

typedef struct{
	Casa* inicio;
	Casa* fim;
	int tamanho;
}Tabuleiro;

typedef struct Jogador{
	char nome[BUFFER];
 	char cor[BUFFER];
 	Casa* posicao;
 	struct Jogador* proximo;
 	struct Jogador* anterior;
}Jogador;

typedef struct{
	Jogador* inicio;
	Jogador* fim;
	int quantidade;
}Jogadores;

void removerQuebraLinha(char* str){
	str[strcspn(str, "\n")] = '\0';
}

void inicializarTabuleiro(Tabuleiro* tabuleiro){
	tabuleiro->inicio = NULL;
	tabuleiro->fim = NULL;
	tabuleiro->tamanho = 0;
}

void criarPosicoes(Tabuleiro* tabuleiro){
	Casa* nova = (Casa*) malloc(sizeof(Casa));
	if(nova == NULL){
		printf("ERRO AO ALOCAR MEMÓRIA!");
		exit(EXIT_FAILURE);
	}
	
	nova->posicao = tabuleiro->tamanho + 1;
	nova->proximo = NULL;
	nova->anterior = NULL;
	
	if(tabuleiro->inicio == NULL){
		tabuleiro->inicio = nova;
		tabuleiro->fim = nova;
	}
	else{
		tabuleiro->fim->proximo = nova;
		nova->anterior = tabuleiro->fim;
		tabuleiro->fim = nova; 
	} 
	
	tabuleiro->tamanho++;
}

void inicializarJogadores(Jogadores* jogadores){
	jogadores->inicio = NULL;
	jogadores->fim = NULL;
	jogadores->quantidade = 0;
}

void criarJogadores(Jogadores* jogadores, Tabuleiro* tabuleiro){
		Jogador* novo = (Jogador*) malloc(sizeof(Jogador));
		if(novo == NULL){ printf("ERRO AO ALOCAR MEMÓRIA!"); exit(EXIT_FAILURE);}
			
		printf("\n====== CADASTRAR JOGADOR %d ======\n", jogadores->quantidade + 1);
		
		printf("Digite o nome do jogador %d: ", jogadores->quantidade + 1);
		fgets(novo->nome, sizeof(novo->nome), stdin);
		removerQuebraLinha(novo->nome);
			
		printf("Digite a cor do jogador %d: ", jogadores->quantidade + 1);
		fgets(novo->cor, sizeof(novo->cor), stdin);
		removerQuebraLinha(novo->cor);
		
		novo->posicao = tabuleiro->inicio;
			
		novo->proximo = NULL;
		novo->anterior = NULL;
			
		if(jogadores->inicio == NULL){
			jogadores->inicio = novo;
			jogadores->fim = novo;
			novo->proximo = jogadores->inicio;
			novo->anterior = jogadores->fim;
		}
		else{
			jogadores->fim->proximo = novo;
			novo->anterior = jogadores->fim;
			jogadores->fim = novo;
			jogadores->fim->proximo = jogadores->inicio;
			jogadores->inicio->anterior = jogadores->fim;
		}
		
		jogadores->quantidade++;
}

void movimento(Jogador* jogador, int valor){
	
	for(int i = 0; i < valor && jogador->posicao->proximo != NULL; i++){
		jogador->posicao = jogador->posicao->proximo;
	}
}

int jogarDado(int num){
	int menor = 1, maior = 6;
	return num = (rand() % (maior - menor + 1)) + menor;
}

void placar(Jogadores* jogadores){
	Jogador* aux = jogadores->inicio;
	
	printf("\n===== PLACAR =====\n");
	
	for(int i = 0; i < jogadores->quantidade; i++){
		printf("%s (%s): %d\n", aux->nome, aux->cor, aux->posicao->posicao);
		aux = aux->proximo;	
	}
}

void partida(Jogadores* jogadores, Tabuleiro* tabuleiro){
	bool vencedor = false;
	Jogador* atual = jogadores->inicio;
	
	while(!vencedor){
		placar(jogadores);
		printf("Aperte enter para jogar o dado: ");
		getchar();
		
		int dado = jogarDado(dado);
		printf("%s tirou %d\n", atual->nome, dado);
		movimento(atual, dado);
		
		if(atual->posicao->proximo == NULL){
			printf("%s venceu!\n", atual->nome);
			vencedor = true;
		}
		atual = atual->proximo;
	}
	
}


int main(){
	setlocale(LC_ALL, "");
	
	Tabuleiro tabuleiro;
	inicializarTabuleiro(&tabuleiro);
	
	Jogadores jogadores;
	inicializarJogadores(&jogadores);
	
	int quantPosicoes;
	printf("Qual o tamanho do tabuleiro?: ");
	scanf("%d", &quantPosicoes);
	getchar();
	
	for(int i = 0; i < quantPosicoes; i++) criarPosicoes(&tabuleiro);
	
	int quantJogadores;
	printf("Digite a quantidade de jogadores que desejam jogar: ");
	scanf("%d", &quantJogadores);
	getchar();
	
	for(int i = 0; i < quantJogadores; i++) criarJogadores(&jogadores, &tabuleiro);
	
	partida(&jogadores, &tabuleiro);
	
	return 0;
}
