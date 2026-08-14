#include <stdio.h>

int main(){
    int *p1, x = 100;
    p1 = &x;
    *p1 = 200;

    printf("%p\n", p1);
    printf("%i\n", *p1);
    printf("%i\n", x);

    if(p1 == NULL){
        printf("Nulo!\n");
    }
    else{
        printf("não nulo!\n");
    }

    p1 = NULL;

    printf("%p\n", p1);

    if(p1 == NULL){
        printf("Nulo!\n");
    }
    else{
        printf("Não nulo!\n");
    }

    return 0;
}