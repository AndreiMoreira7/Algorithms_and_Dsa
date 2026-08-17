#include <stdio.h>
#define TAMANHO 4

typedef struct{
    int valor;
}Celula;

void ler_valores(Celula celulas[TAMANHO][TAMANHO]){
    for(int i = 0; i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO; j++){
            printf("Digite o valor da posição [%d, %d]: ", i, j);
            scanf("%d", &celulas[i][j].valor);
        }
    }
}

void imprimir_diagonal(Celula celulas[TAMANHO][TAMANHO]){
    for(int i = 0; i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO; j++){
            if(i == j){
                printf("indice: [%d, %d], valor: [%d]\n", i, j, celulas[i][j].valor);
            }
        }
    }
}

int main(){
    Celula celulas[TAMANHO][TAMANHO];

    ler_valores(celulas);
    imprimir_diagonal(celulas);

    return 0;
}