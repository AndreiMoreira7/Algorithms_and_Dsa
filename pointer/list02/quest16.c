#include <stdio.h>

int main(){
    int num1, num2, num3, *maior;

    printf("Digite três números no formato [N1 N2 N3]: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    maior = &num1;

    if(num2 > *maior){
        *maior = num2;
    }

    if(num3 > *maior){
        *maior = num3;
    }

    printf("o maior número é [%d]", *maior);

    return 0;
}