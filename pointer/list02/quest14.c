#include <stdio.h>

void trocar(int *pnum1, int *pnum2){
    *pnum1 += *pnum2;
    *pnum2 = *pnum1 - *pnum2;
    *pnum1 -= *pnum2;
}

int main(){
    int num1 = 10, num2 = 20;

    printf("num1 before: %d | num2 before: %d\n", num1, num2);

    trocar(&num1, &num2);   

    printf("num1 now: %d | num2 now: %d", num1, num2);

    return 0;
}