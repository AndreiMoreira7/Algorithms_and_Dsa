#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define BUFFER_URL 200
#define BUFFER_TITULO 200

typedef struct Site{
	char url[BUFFER_URL];
	char titulo[BUFFER_TITULO];
	struct Site* proximo;
	struct Site* anterior;
}Site;

typedef struct{
	Site* inicio;
	Site* fim;
	Site* atual;
	int quantSites;
}Navegador;

void removerQuebraLinha(char* str){
	str[strcspn(str, "\n")] = '\0';
}

void inicializar(Navegador* navegador){
	navegador->inicio = NULL;
	navegador->fim = NULL;
	navegador->quantSites = 0;	
}

bool semVisitas(Navegador* navegador){
	return navegador->inicio == NULL;
}

void registrarPagina(Navegador* navegador){
	Site* novo = (Site*) malloc(sizeof(Site));
	if(novo == NULL){
		printf("ERRO AO ALOCAR MEMÓRIA!");
		exit(EXIT_FAILURE);
	}
	else{
		printf("Digite o titulo do site que deseja entrar: ");
		fgets(novo->titulo, sizeof(novo->titulo), stdin);
		removerQuebraLinha(novo->titulo);
		
		printf("Digite a URL do site que deseja visitar: ");
		fgets(novo->url, sizeof(novo->url), stdin);
		removerQuebraLinha(novo->url);
		
		novo->anterior = NULL;
		novo->proximo = NULL;
		
		if(semVisitas(navegador)){
			navegador->inicio = novo;
			navegador->fim = novo;
			navegador->atual = novo;
		}
		else{
			novo->anterior = navegador->fim;
			novo->anterior->proximo = novo;
			navegador->fim = novo;
			navegador->atual = novo;
		}
		navegador->quantSites++;
	}
}

void paginaAnterior(Navegador* navegador){
	if(semVisitas(navegador)) printf("O histórico está vazio, você não visitou sites!");
	else if(navegador->atual->anterior == NULL) printf("Não tem sites anteriores!");
	else{
		navegador->atual = navegador->atual->anterior;
		printf("Ok, agora estamos no site com titulo: %s", navegador->atual->titulo);	
	}
}

void proximaPagina(Navegador* navegador){
	if(semVisitas(navegador)) printf("O histórico está vazio, você não visitou sites!");
	else if(navegador->atual->proximo == NULL) printf("Não tem próximo site!");
	else{
		navegador->atual = navegador->atual->proximo;
		printf("Ok, agora estamos no site com titulo: %s", navegador->atual->titulo);
	}
}

void historico(Navegador* navegador){
	if(semVisitas(navegador)) printf("Seu histórico está vazio!");
	else{
		Site* aux = navegador->inicio;
		int contador = 1;
		
		printf("\n====== HISTÓRICO ======\n");
		while(aux != NULL){
			printf("Site %d:\n", contador++);
			printf("TITULO: %s\n", aux->titulo);
			printf("URL: %s\n\n", aux->url);
			
			aux = aux->proximo;
		}
	}
}

void quantSitesArmazenados(Navegador* navegador){
	if(semVisitas(navegador)) printf("Não tem sites armazenados!");
	else{
		printf("A quantidade de sites armazenados é %d", navegador->quantSites);
	}
}

void limparHistorico(Navegador* navegador){
	if(semVisitas(navegador)) printf("O histórico já está vazio!");
	else{
		Site* aux;
		int quant = navegador->quantSites;
		
		for(int i = 0; i < quant; i++){
			aux = navegador->inicio;
			navegador->inicio = navegador->inicio->proximo;
			free(aux);
			navegador->quantSites--;
		}
		
		printf("Histórico limpo com sucesso!");
	}
	inicializar(navegador);
}

int main(){
	setlocale(LC_ALL, "");
	
	Navegador navegador;
	inicializar(&navegador);
	
	int opcao = 0;
	bool validar = true;
	
	while(validar){
		printf("\n======= NAVEGADOR =======\n");
		printf("1) Registrar nova página visualizada\n");
		printf("2) Voltar para a página anterior\n");
		printf("3) Avançar para a página seguinte\n");
		printf("4) Exibir todo o histórico\n");
		printf("5) Exibir a quantidade de páginas armazenadas\n");
		printf("6) Limpar o histórico completamente\n");
		printf("7) Sair\n");
		printf("Digite uma opção: ");
		scanf("%d", &opcao);
		getchar();
		
		switch(opcao){
			case 1:
				registrarPagina(&navegador);
				break;
			case 2:
				paginaAnterior(&navegador);
				break;
			case 3:
				proximaPagina(&navegador);
				break;
			case 4:
				historico(&navegador);
				break;
			case 5:
				quantSitesArmazenados(&navegador);
				break;
			case 6:
				limparHistorico(&navegador);
				break;
			case 7:
				validar = false;
				break;
			default:
				printf("Opção inválida, digite novamente!");
				break;
		}
	}
	
	free(&navegador);
	return 0;
}
