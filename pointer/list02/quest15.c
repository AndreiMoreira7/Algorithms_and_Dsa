#include <stdio.h>

int main(){
    int num = 0, *fat;

    printf("Digite um num e mostraremos o fatorial dele: ");
    scanf("%d", &num);

    fat = &num; 

    for(int i = *fat - 1; i > 0; i--){
        *fat *= i;
        if(i == 1){
            printf("[%d] ", *fat *= i);
        }
    }

    return 0;
}