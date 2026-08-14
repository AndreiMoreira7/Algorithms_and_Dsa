#include <stdio.h>
#include <math.h>

void eh_primo(int num){
    for(int i = num - 1; i > sqrt(num); i--){
        if(num % i == 0){
            printf("0");
            return;
        }
    }
    printf("1");
    return;
}

int main(){
    int num = 0;

    printf("Digite um número inteiro e lhe direi se é primo ou não: ");
    scanf("%d", &num);

    eh_primo(num);

    return 0;
}