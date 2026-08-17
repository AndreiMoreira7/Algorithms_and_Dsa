#include <stdio.h>

int main(){
    int i, *p, *q;
    i = 5;
    p = &i;
    q = p;
    i = 10;

    printf("i == [%d][%p]\np == [%i][%p]\nq == [%i][%p]", i, &i, *p, &p, *q, &q);

    return 0;
}