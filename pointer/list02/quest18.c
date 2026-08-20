#include <stdio.h>
#define TAMANHO 5

void set_valores(int *vetor){
    for(int i = 0; i < TAMANHO; i++){
        printf("Digite o número que ficará na posição %d: ", i);
        scanf("%d", &vetor[i]);
    }
}

void valores_quadrado(int *vetor){
    for(int i = 0; i < TAMANHO; i++){
        printf("Posição -> [%d] | Valor ao quadrado -> [%d]\n", i, vetor[i] * vetor[i]);
    }
}

int main(){
    int vetor[TAMANHO];

    set_valores(&vetor[0]);
    valores_quadrado(&vetor[0]);

    return 0;
}