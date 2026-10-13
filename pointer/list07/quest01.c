#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

#define TAMANHO_CODIGO 20
#define TAMANHO_TITULO 100
#define TAMANHO_AUTOR 50

typedef struct Livro{
    char codigo[TAMANHO_CODIGO];
    char titulo[TAMANHO_TITULO];
    char autor[TAMANHO_AUTOR];
    struct Livro* proximo;
    struct Livro* anterior;
}Livro;

typedef struct{
    Livro* inicio;
    Livro* fim;
    int tamanho;
}Biblioteca;

void removerQuebraLinha(char* str){
    str[strcspn(str, "\n")] = '\0';
}

void inicializar(Biblioteca* biblioteca){
    biblioteca->inicio = NULL;
    biblioteca->fim = NULL;
    biblioteca->tamanho = 0;
}

bool bibliotecaVazia(Biblioteca* biblioteca){
    return biblioteca->inicio == NULL;
}

void inserirInicio(Biblioteca* biblioteca){
    Livro* novo = (Livro*) malloc(sizeof(Livro));
    if(novo == NULL){
        printf("ERRO AO ALOCAR MEMÓRIA");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Digite o titulo do livro: ");
        fgets(novo->titulo, sizeof(novo->titulo), stdin);
        removerQuebraLinha(novo->titulo);

        printf("Digite o nome do autor do livro: ");
        fgets(novo->autor, sizeof(novo->autor), stdin);
        removerQuebraLinha(novo->autor);

        printf("Digite o código do livro: ");
        fgets(novo->codigo, sizeof(novo->codigo), stdin);
        removerQuebraLinha(novo->codigo);

        if(bibliotecaVazia(biblioteca)){
            biblioteca->inicio = novo;
            biblioteca->fim = novo;
        }
        else{
            biblioteca->inicio->anterior = novo;
            novo->proximo = biblioteca->inicio;
            biblioteca->inicio = novo;
        }

        biblioteca->tamanho++;
    }
}

void inserirFim(Biblioteca* biblioteca){
    Livro* novo = (Livro*) malloc(sizeof(Livro));
    if(novo == NULL){
        printf("ERRO AO ALOCAR MEMÓRIA");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Digite o titulo do livro: ");
        fgets(novo->titulo, sizeof(novo->titulo), stdin);
        removerQuebraLinha(novo->titulo);

        printf("Digite o nome do autor do livro: ");
        fgets(novo->autor, sizeof(novo->autor), stdin);
        removerQuebraLinha(novo->autor);

        printf("Digite o código do livro: ");
        fgets(novo->codigo, sizeof(novo->codigo), stdin);
        removerQuebraLinha(novo->codigo);

        if(bibliotecaVazia(biblioteca)){
            biblioteca->inicio = novo;
            biblioteca->fim = novo;
        }
        else{
            biblioteca->fim->proximo = novo;
            novo->anterior = biblioteca->fim;
            biblioteca->fim = novo;
        }

        biblioteca->tamanho++;
    }
}

void inserir(Biblioteca* biblioteca){
    int opcao;
    printf("Você deseja inserir o livro no fim(1) ou no inicio(2) da prateleira?: ");
    scanf("%d", &opcao);
    getchar();

    switch(opcao){
        case 1:
            inserirFim(biblioteca);
            break;
        case 2:
            inserirInicio(biblioteca);
            break;
        default:
            printf("Opção inválida!");
            break;
    }
}

void exibir(Biblioteca* biblioteca){
    if(bibliotecaVazia(biblioteca)) printf("A biblioteca está vazia!");
    else{
        Livro* aux = biblioteca->inicio;
        int contador = 0;

        while(aux != NULL){
            printf("====== LIVRO %d ======");
            printf("TITULO: %s\nAUTOR: %s\nCODIGO: %s\n\n", aux->titulo, aux->autor, aux->codigo);

            aux = aux->proximo;
            contador++;
        }
    }
}

void exibirInvertido(Biblioteca* biblioteca){
    if(bibliotecaVazia(biblioteca)) printf("A biblioteca está vazia!");
    else{
        Livro* aux = biblioteca->fim;
        int contador = 0;

        while(aux != NULL){
            printf("====== LIVRO %d ======");
            printf("TITULO: %s\nAUTOR: %s\nCODIGO: %s\n\n", aux->titulo, aux->autor, aux->codigo);

            aux = aux->anterior;
            contador++;
        }
    }
}

int main(){
    setlocale(LC_ALL, "");

    Biblioteca biblioteca;
    inicializar(&biblioteca);

    int opcao = 0;
    bool validar = true;

    while(validar){
        printf("\n======= BIBLIOTECA =======\n");
        printf("1) Inserir livro\n");
        printf("2) Exibir do começo pro fim\n");
        printf("3) Exibir do fim pro começo\n");
        printf("4) Sair\n");
        printf("Digite uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 1:
                inserir(&biblioteca);
                break;
            case 2:
                exibir(&biblioteca);
                break;
            case 3:
                exibirInvertido(&biblioteca);
                break;
            case 4:
                validar = false;
                break;
            default:
                printf("Opção inválida, tente novamente!");
                break;
        }
    }

    return 0;
}