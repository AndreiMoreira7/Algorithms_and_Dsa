#include <stdio.h>

int main(){
    int x = 14;
    int *p1, *p2;
    p1 = &x;

    printf("%d\n", x);
    printf("%p\n", &x);
    printf("%p\n", p1);
    p2 = p1;
    printf("%p\n", p2);
    *p2 = 20;
    printf("%d\n", x);

    return 0;
}
