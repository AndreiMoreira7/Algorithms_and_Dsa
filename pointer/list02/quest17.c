#include <stdio.h>

void multiplicar(float *pnum){
    *pnum *= 3;
}

int main(){
    float num = 0;

    printf("Digite um numero: ");
    scanf("%f", &num);

    printf("O valor de num antes de multiplicar é [%.2f]", num);
    multiplicar(&num);
    printf("O valor de num depois de multiplicar é [%.2f]", num);

    return 0;
}