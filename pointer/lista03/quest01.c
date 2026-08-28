#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct No{
    int data;
    struct No *prox;
}No;

typedef struct{
    No *inicio;
    No *fim;
}Fila;

void inicializar(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL; 
}

bool filaVazia(Fila *fila){
    return fila->inicio == NULL;
}

void enfileirar(Fila *fila, int valor){
    No *novo = (No*) malloc (sizeof(No)); 
    novo->data = valor;
    novo->prox = NULL;

    if(filaVazia(fila)){
        fila->inicio = novo;
        fila->fim = novo; 
    }
    else{
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

void desenfileirar(Fila *fila){
    if(filaVazia(fila)){
        printf("não há oque remover, a fila está vazia");
    }
    else{
        No* aux = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(aux);
        if(fila->inicio == NULL){
            fila->fim = NULL;
        }
    }
}

void imprimir(Fila *fila){
    if(filaVazia(fila) == true){
        printf("Fila vazia, não há oque imprimir");
    }
    else{
        No * atual = fila->inicio;
        while(atual != NULL){
            printf("[%d] ", atual->data);
            atual = atual->prox;
        }
    }
}

void obter_frente(Fila *fila){
    if(fila->inicio == NULL){
        printf("não há elementos para mostrar!\n");
    }
    else{
        printf("[%d]", fila->inicio->data);
    }
}


int main(){
    Fila fila;
    inicializar(&fila);
    int opcao = 0, valor = 0;
    bool validar = true;

    while(validar == true){
        printf("\n======= Digite uma opção =======\n1. Verificar se a fila está vazia\n2. Obter frente\n3. Enfileirar\n4. Desenfileirar\n5. Imprimir\n6. Sair\n:");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: 
                if(filaVazia(&fila) == true){printf("A fila está vazia");}
                else{printf("Não está vazia");}
                break;
            case 2:
                obter_frente(&fila);
                break;
            case 3:
                printf("Digite o número a ser enfileirado: ");
                scanf("%d", &valor);
                enfileirar(&fila, valor);
                break;
            case 4:
                desenfileirar(&fila);
                break;
            case 5:
                imprimir(&fila);
                break;
            case 6:
                validar = false;
            default:
                printf("o número digitado não condiz as opções");
        }
    }

    return 0;
}