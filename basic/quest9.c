#include <stdio.h>

int main(){
    int num = 0;

    printf("input a num: ");
    scanf("%d", &num);

    while(num > 0){
        printf("[%d] ", num);
        num--;
    }

    return 0;
}