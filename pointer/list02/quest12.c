#include <stdio.h>

int main(){
    int a = 10;
    int *x;
    x = & a;
    *x = 55;

    printf("a == [%d]", a);

    return 0;
}