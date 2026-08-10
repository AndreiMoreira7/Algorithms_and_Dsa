#include<stdio.h>

int main(){
    int num = 0;
    int soma = 0;
    
    printf("Digite um num: ");
    scanf("%d", &num);
    
    for(int i = 1; i <= num; i++){
        soma += i;
    }
    printf("%d", soma);
    
return 0;
}