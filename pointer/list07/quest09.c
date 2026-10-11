#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

#define TAMANHO_URL 400
#define TAMANHO_TITULO 50
#define TAMANHO_ARTISTA 30

typedef struct Musica{
	int codigo;
	char titulo[TAMANHO_TITULO];
	char artista[TAMANHO_ARTISTA];
	int duracao;
	struct Musica* proxima;
	struct Musica* anterior;
}Musica;

typedef struct{
	Musica* inicio;
	Musica* fim;
	Musica* atual;
	int tamanho;
}Playlist;

void removerQuebraLinha(char* str){
	str[strcspn(str, "\n")] = '\0';
}

void inicializar(Playlist* playlist){
	playlist->inicio = NULL;
	playlist->fim = NULL;
	playlist->atual = NULL;
	playlist->tamanho = 0;
}

bool playlistVazia(Playlist* playlist){
	return playlist->inicio == NULL;
}

void adicionarMusica(Playlist* playlist){
	Musica* nova = (Musica*) malloc(sizeof(Musica));
	if(nova == NULL){printf("ERRO AO ALOCAR MEMÓRIA!"); exit(EXIT_FAILURE);}
	
	printf("Digite o nome da música que deseja adicionar: ");
	fgets(nova->titulo, sizeof(nova->titulo), stdin);
	removerQuebraLinha(nova->titulo);
	
	printf("Digite o nome do Artista/Banda que canta a música: ");
	fgets(nova->artista, sizeof(nova->artista), stdin);
	removerQuebraLinha(nova->artista);
	
	printf("Digite a duração da música em segundos: ");
	scanf("%d", &nova->duracao);
	getchar();
	
	nova->codigo = playlist->tamanho + 1;
	
	nova->anterior = NULL;
	nova->proxima = NULL;
	
	if(playlistVazia(playlist)){
		playlist->inicio = nova;
		playlist->fim = nova;
		nova->anterior = nova;
		nova->proxima = nova;
	}
	else{
		playlist->fim->proxima = nova;
		nova->anterior = playlist->fim;
		playlist->fim = nova;
		playlist->fim->proxima = playlist->inicio;
		playlist->inicio->anterior = playlist->fim;
	}
	
	playlist->tamanho++;
}

void removerMusica(Playlist* playlist){
	if(playlistVazia(playlist)) printf("A playlist está vazia!");
	else{
		int codigo;
		printf("Digite o código da música que deseja excluir: ");
		scanf("%d", &codigo);
		getchar();
		
		Musica* aux = playlist->inicio;
		
		do{
			if(aux->codigo == codigo){
				if(aux == playlist->inicio){
					if(playlist->inicio == playlist->fim){
						playlist->fim = NULL;
						playlist->inicio = NULL;
					}
					else{
						playlist->inicio = playlist->inicio->proxima;
						playlist->inicio->anterior = playlist->fim;
					}
				}
				else if(aux == playlist->fim){
					playlist->fim = playlist->fim->anterior;
					playlist->fim->proxima = playlist->inicio;
				}
				else{
					aux->anterior->proxima = aux->proxima;
					aux->proxima->anterior = aux->anterior;
				}
				
				free(aux);
				playlist->tamanho--;
				printf("Música encontrada e removida com sucesso!");
				return;
			}
			else{
				aux = aux->proxima;
			}
		}
		while(aux != playlist->inicio);
		
		printf("A música não existe na playlist!");
	}
}

void tocarMusica(Playlist* playlist){
	Musica* aux = playlist->inicio;
	
	char nome[TAMANHO_TITULO];
	printf("Digite o nome da música que está na playlist e você deseja ouvir: ");
	fgets(nome, sizeof(nome), stdin);
	removerQuebraLinha(nome);
	
	do{
		if(strcmp(aux->titulo, nome) == 0){
			playlist->atual = aux;

			char url[TAMANHO_URL];
			sprintf(url, "https://www.youtube.com/results?search_query=%s+%s", aux->titulo, aux->artista);
			
			for(int i = 0; url[i] != '\0'; i++){
				if(url[i] == ' ') url[i] = '+';
			}
			
			
			char comando[TAMANHO_URL];
	
			sprintf(comando, "start %s", url);
			
			system(comando);	
			printf("Musica rodando em segundo plano...");
			return;	
		}
		else{
			aux = aux->proxima;
		}
	} 
	while(aux != playlist->inicio);
	
	printf("A música não foi encontrada!");
}

void exibirMusicas(Playlist* playlist){
	if(playlistVazia(playlist)) printf("A playlist está vazia!");
	else{
		Musica* aux = playlist->inicio;
		
		printf("====== MÚSICAS ======\n");
		do{
			printf("%s - %s (%d segundos)\n", aux->artista, aux->titulo, aux->duracao);
			aux = aux->proxima;
		}
		while(aux != playlist->inicio);
	}
}

void localizarMusica(Playlist* playlist){
	if(playlistVazia(playlist)) printf("A playlist está vazia!");
	else{
		int codigo;
		printf("Digite o código da música que deseja localizar: ");
		scanf("%d", &codigo);
		getchar();
		
		Musica* aux = playlist->inicio;
		
		do{
			if(aux->codigo == codigo){
				printf("A música foi localizada com sucesso!");
				return;
			}
			else{
				aux = aux->proxima;
			}
		}
		while(aux != playlist->inicio);
		
		printf("A música digitada não existe na playlist!");
	}
}

void proximaMusica(Playlist* playlist){
	if(playlistVazia(playlist)){
		printf("A playlist está vazia!\n");
		return;
	}
	
	if(playlist->atual == NULL){
		playlist->atual = playlist->inicio;
	}
	else{
		playlist->atual = playlist->atual->proxima;
	}
	
	
	char url[TAMANHO_URL];
	sprintf(url, "https://www.youtube.com/results?search_query=%s+%s", playlist->atual->titulo, playlist->atual->artista);
	
	for(int i = 0; url[i] != '\0'; i++){
		if(url[i] == ' ') url[i] = '+';
	}
	
	char comando[TAMANHO_URL];
	sprintf(comando, "start %s", url);
	
	system(comando);	
	printf("Tocando agora: %s - %s (%d segundos)\n", playlist->atual->artista, playlist->atual->titulo, playlist->atual->duracao);
}

int main(){
	setlocale(LC_ALL, "");
	
	Playlist playlist;
	inicializar(&playlist);
	
	int opcao = 0;
	bool validar = true;
	
	while(validar){
		printf("\n======== PLAYLIST ========\n");
		printf("1) Adicionar música\n");
		printf("2) Remover música pelo código\n");
		printf("3) Tocar música atual\n");
		printf("4) Avançar para a próxima música\n");
		printf("5) Exibir as músicas da playlist\n");
		printf("6) Localizar música pelo código\n");
		printf("7) Sair\n");
		printf("Digite uma opção: ");
		scanf("%d", &opcao);
		getchar();
		
		switch(opcao){
			case 1:
				adicionarMusica(&playlist);
				break;
			case 2:
				removerMusica(&playlist);
				break;
			case 3:
				tocarMusica(&playlist);
				break;
			case 5:
				exibirMusicas(&playlist);
				break;
			case 6:
				localizarMusica(&playlist);
				break;
			case 7:
				validar = false;
				break;
			default:
				printf("Opção inválida, tente novamente!");
				break;
		}
	}
	
	return 0;
}
