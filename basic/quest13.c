#include <stdio.h>

int main(){
    float notas = 0;
    float media = 0;
    int quantidadeNotas = 0;

    do{
        printf("Digite a nota de numero %d: ", quantidadeNotas + 1);
        if (scanf("%f", &notas) >= 0){
            if (notas <= 10 && notas >= 0){
                media += notas;
                quantidadeNotas++;
            }
            if(notas > 10){
                printf("nota não pode ser maior que 10, tente novamente\n");
            }
        }
    } while (notas >= 0);

    printf("nota menor que 0, encerrando o programa\n");

    if(media > 0){
        media /= quantidadeNotas;
        printf("A média é %.2f", media);
    }
    else{
        printf("não tem média, não podemos fazer divisão por 0");
    }

    return 0;
}