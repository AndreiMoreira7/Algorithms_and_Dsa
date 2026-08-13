#include <stdio.h>
#define TAMANHO 3

int ler_nums(int vetor[TAMANHO][TAMANHO]){
    for(int i = 0; i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO; j++){
            printf("Digite o num que ficará na posição [%d][%d]: ", i, j);
            scanf("%d", &vetor[i][j]);
        }
    }

    return vetor;
}

void somar_nums(int vetor[TAMANHO][TAMANHO], int soma){
    int indice_j = TAMANHO - 1;
    int indice_i = 0;

    for(int i = 0; i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO; j++){
            if(i == j){
                soma += vetor[i][j];
            }
            if((i == indice_i && j == indice_j)){
                soma += vetor[i][j];
                indice_i++;
                indice_j--;
            }
        }
    }

    printf("A soma dos números é [%d]", soma);
}

int main(){
    int vetor[TAMANHO][TAMANHO];
    int soma = 0;
    ler_nums(vetor);
    somar_nums(vetor, soma);

    return 0;
}