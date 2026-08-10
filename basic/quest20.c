#include <stdio.h>
#define TAMANHO 3

void ler_e_identificar(int vetor[TAMANHO][TAMANHO]){
    for(int i = 0; i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO; j++){
            printf("Digite 1 ou 0 na posição [%d][%d]: ", i, j);
            scanf("%d", &vetor[i][j]);

            if((i == j && vetor[i][j] != 1) || i != j && vetor[i][j] != 0){
                printf("não é uma matriz identidade");
                return;
            }
        }
    }

    printf("É uma matriz identidade");
}

int main(){
    int vetor[TAMANHO][TAMANHO];

    ler_e_identificar(vetor);

    return 0;
}