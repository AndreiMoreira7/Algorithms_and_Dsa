#include <stdio.h>
#define TAMANHO 3

int main(){
    int vetor[TAMANHO][TAMANHO];
    int soma = 0;

    for(int i = 0; i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO; j++){
            printf("Digite o número que ficará na posição [%d][%d]: ", i, j);
            scanf("%d", &vetor[i][j]);
            soma += vetor[i][j];
        }
    }

    printf("A soma dos valores da matriz é [%d]", soma);

    return 0;
}