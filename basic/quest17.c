#include <stdio.h>
#define TAMANHO 8

int main(){
    int vetor[TAMANHO];

    for(int i = 0; i < TAMANHO; i++){
        printf("Digite o número que ficará na posição %d do vetor: ", i);
        scanf("%d", &vetor[(TAMANHO - i) - 1]);
    }

    for(int i = 0; i < TAMANHO; i++){
        printf("[%d] ", vetor[i]);
    }

    return 0;
}