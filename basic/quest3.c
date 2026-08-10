#include <stdio.h>

int main(){
    int num = 0;

    printf("digite um num: ");
    scanf("%d", &num);

    if(num % 2 == 0){
        printf("é par");
    }
    else{
        printf("é impar");
    }

    return 0;
}