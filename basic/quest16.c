#include <stdio.h>
#define TAMANHO 5

int main(){
    int vetor[TAMANHO];
    int maior = 0;
    int menor = 0;

    for(int i = 0; i < TAMANHO; i++){
        printf("Digite o número que ficará na posição %d do vetor: ", i);
        scanf("%d", &vetor[i]);
        if(i == 0){
            menor = vetor[i];
        }
        else{
            if(vetor[i] < menor){
                menor = vetor[i];
            }
        }
        if(vetor[i] > maior){
            maior = vetor[i];
        }
    }

    printf("o maior número é [%d] e o menor é [%d]", maior, menor);

    return 0;
}