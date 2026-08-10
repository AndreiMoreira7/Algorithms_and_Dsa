#include <stdio.h>
#define TAMANHO 10

int main(){
    int vetor[TAMANHO];
    int aux = 0;

    for(int i = 0; i < TAMANHO; i++){
        printf("Digite o %dª número: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    for(int i = 0; i < TAMANHO - 1; i++){
        for(int j = 0; j < TAMANHO - i - 1; j++){
            if(vetor[j] > vetor[j + 1]){
                aux = vetor[j + 1];
                vetor[j + 1] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    
    for(int i = 0; i < TAMANHO; i++){
        printf("[%d] ", vetor[i]);
    }
    
    return 0;
}