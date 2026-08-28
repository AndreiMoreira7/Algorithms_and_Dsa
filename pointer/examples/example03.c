#include <stdio.h>

int main(){
    int num = 15;
    int *ptr;

    ptr = &num;

    printf("o valor de num é %d\n o endereço de memoria de num é %p\nconteudo apontado por ptr é %d\no endereço apontado por ptr é %p", num, &num, *ptr, ptr);

    return 0;
}