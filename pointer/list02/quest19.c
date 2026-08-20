#include <stdio.h>
#define TAMANHO 10

int main(){
    float arr[TAMANHO];

    for(int i = 0; i < TAMANHO; i++){
        printf("Digite o número que ficará na posição [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < TAMANHO; i++){
        printf("o endereço de memoria do indice [%d] é [%d]\n", i, &arr[i]);
    }

    return 0;
}