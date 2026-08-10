#include <stdio.h>

int main(){
    int num = 0;

    printf("input a number: ");
    scanf("%d", &num);

    for(int i = num - 1; i > 0; i--){
        num *= i;
    }

    printf("%d", num);

return 0;
}