#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Aviao{
	int numPassageiros;
	char marca[50];
	char modelo[50];
	char destino[50];
	struct Aviao* proximo;
}Aviao;

typedef struct{
	Aviao* inicio;
	Aviao* fim;
	int quant;
}Pista;

void inicializar(Pista* pista){
	pista->inicio = NULL;
	pista->fim = NULL;
	pista->quant = 0;
}

bool pistaVazia(Pista* pista){
	return pista->inicio == NULL;
}

void entradaAviao(Pista* pista, int numPassageiros, char marca[], char modelo[], char destino[]){
	Aviao* novo = (Aviao*) malloc (sizeof(Aviao));
	if(novo == NULL){
		printf("erro ao alocar memória");
		return;
	}
	
	novo->numPassageiros = numPassageiros;
	strcpy(novo->destino, destino);
	strcpy(novo->marca, marca);
	strcpy(novo->modelo, modelo);
	novo->proximo = NULL;
	
	if(pistaVazia(pista) == true){
		pista->inicio = novo;
		pista->fim = novo;
		printf("O primeiro avião foi colocado na pista com sucesso!");
	}
	else{
		pista->fim->proximo = novo;
		pista->fim = novo;
		printf("Mais um avião colocado na pista com sucesso!");
	}
	pista->quant++;
}

void decolagemAviao(Pista* pista){
	if(pistaVazia(pista) == true) printf("não há aviões para decolar, a pista está vazia!");
	else{
		Aviao* aux = pista->inicio;
		pista->inicio = pista->inicio->proximo;
		free(aux);
		pista->quant--;
		if(pista->inicio == NULL) pista->fim = NULL;
	}
}

void numAvioes(Pista* pista){
	if(pistaVazia(pista) == true) printf("Não há aviões na pista!");
	else printf("O número de aviões esperando para decolar é [%d]", pista->quant);
}

void listarAvioes(Pista* pista){
	if(pistaVazia(pista) == true) printf("Não há aviões na pista!");
	else{
		Aviao* atual = pista->inicio;
		printf("========= Info aviões =========");
		while(atual != NULL){
			printf("\nMarca: %s\nModelo: %s\nDestino: %s\nQuantidade de pessoas: %d\n", atual->marca, atual->modelo, atual->destino, atual->numPassageiros);
			atual = atual->proximo;
		}
	}
}

void proxAviao(Pista* pista){
	if(pistaVazia(pista) == true) printf("Não há aviões na pista");
	else printf("\nINFOS DO PROX AVIÃO:\n- Marca: %s\n- Modelo: %s\n- Destino: %s\n- Quantidade de pessoas: %d\n", pista->inicio->marca, pista->inicio->modelo, pista->inicio->destino, pista->inicio->numPassageiros);
}

void limparQuebraLinha(char* str){
	str[strcspn(str, "\n")] = '\0';
}

int main(){
	Pista pista;
	inicializar(&pista);
	
	int opcao = 0, numPassageiros = 0;
	bool validarLoop = true;
	char modelo[50], marca[50], destino[50];
	
	while(validarLoop){
		printf("\n\n======== Pista / Aeroporto ========\n");
		printf("1) N° de aviões à espera para decolar\n");
		printf("2) Decolagem de um avião\n");
		printf("3) Entrada de um novo avião para decolar\n");
		printf("4) Listar todos os aviões à espera de decolar\n");
		printf("5) Listar as caracteristicas do proximo avião a decolar\n");
		printf("6) Sair\n");
		printf("Digite uma opção: ");
		scanf("%d", &opcao);
		while(getchar() != '\n');
		
		switch(opcao){
			case 1: numAvioes(&pista); break;
			case 2: decolagemAviao(&pista); break;
			case 3: 
				printf("Digite a marca do avião: ");
				fgets(marca, sizeof(marca), stdin);
				limparQuebraLinha(marca);
				
				printf("Digite o modelo do avião: ");
				fgets(modelo, sizeof(modelo), stdin);
				limparQuebraLinha(modelo);
				
				printf("Digite o destino do avião: ");
				fgets(destino, sizeof(destino), stdin);
				limparQuebraLinha(destino);
				
				printf("Digite a quantidade de passageiros no avião: ");
				scanf("%d", &numPassageiros);
				
				entradaAviao(&pista, numPassageiros, marca, modelo, destino);
				break;
			case 4: listarAvioes(&pista); break;
			case 5: proxAviao(&pista); break;
			case 6: validarLoop = false; break;
			default: printf("Digite uma opção válida"); break;
		}
	}
	
	return 0;
}
