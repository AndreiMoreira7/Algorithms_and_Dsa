#include <stdio.h>

void factorial(){
    int num = 0;
    printf("input a number and we'll tell you its factorial: "); 
    scanf("%d", &num); 
    for (int i = num - 1; i != 1; i--)
    {
        num *= i;
    }

    printf("%d", num);
}

int main(){
    
    factorial();

    return 0;
}