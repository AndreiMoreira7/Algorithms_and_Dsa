#include <stdio.h>

int main(){
    int num = 0;
    int negativos = 0;
    int zeros = 0;
    int positivos = 0;

    while(num != -999){
        printf("Digite um numero: ");
        scanf("%d", &num);

        if(num < 0 && num != -999){
            negativos++;
        }
        else if(num == 0){
            zeros++;
        }
        else if(num > 0){
            positivos++;
        }
        else{
            printf("Numero invalido \n");
        }
    }

    printf("A quantidade de negativos foi: [%d], de positivos foi [%d] e de zeros foi [%d]", negativos, positivos, zeros);

    return 0;
}