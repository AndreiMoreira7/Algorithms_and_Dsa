#include<stdio.h>

int main(){
    int num = 0;
    
    printf("Digite um num: ");
    scanf("%d", &num);
    
    for(int i = 1; i <= 10; i++){
        printf("[%d] ", num * i);
    }
    
return 0;
}