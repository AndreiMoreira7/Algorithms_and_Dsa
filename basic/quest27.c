#include <stdio.h>

void fatorial(int num){
    for(int i = num - 1; i > 0; i--){
        num *= i;
    }

    printf("o fatorial é [%d]" , num);
}

int main(){
    int num = 0;

    printf("Digite um número inteiro e lhe mostrarei o fatorial dele: ");
    scanf("%d", &num);

    fatorial(num);

    return 0;
}