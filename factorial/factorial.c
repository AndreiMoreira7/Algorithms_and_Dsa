#include <stdio.h>

void factorial(){
    int num = 0;
    printf("input a number and we'll tell you its factorial: "); 
    scanf("%d", &num); 
    for (int n = num - 1; n != 1; n--)
    {
        num *= n;
    }

    printf("%d", num);
}

int main(){
    
    factorial();

    return 0;
}