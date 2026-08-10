#include <stdio.h>
#define TAMANHO 10


int main(){
    int vetor[TAMANHO];
    int soma = 0;
    int media = 0;

    for(int i = 0; i < TAMANHO; i++){
        printf("Digite o número da posição %d no vetor: ", i);
        scanf("%d", &vetor[i]);

        soma += vetor[i];
    }
    media = soma / TAMANHO;

    printf("A soma dos números do vetor é [%d] e a média é [%d]", soma, media);

    return 0;
}