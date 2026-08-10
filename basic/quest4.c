#include <stdio.h>

int main(){
    float nota = 0;
    float media = 0;

    for(int i = 0; i < 3; i++){
        printf("digite a nota de número %d: ", i + 1);
        scanf("%f", &nota);
        media += nota;
    }
    media /= 3;

    if(media >= 7 && media <= 10){
        printf("aprovado com média %.2f", media);
    }
    else if(media < 7 && media >= 5){
        printf("recuperação com media %.2f", media);
    }
    else if(media >= 0 && media < 5){
        printf("reprovado com media %.2f", media);
    }
    else{
        printf("nota inválida");
    }

    return 0;
}