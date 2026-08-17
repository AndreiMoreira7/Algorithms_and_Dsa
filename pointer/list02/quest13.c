#include <stdio.h>

int main(){
    int num_int = 10, *point_int;
    float num_float = 25.5, *point_float;
    char letra = 'a', *point_char;

    printf("Antes de modificar com ponteiros:\nint == %d\nfloat == %.2f\nchar == %c\n", num_int, num_float, letra);

    point_int = &num_int;
    point_float = &num_float;
    point_char = &letra;

    *point_int = 100;
    *point_float = 150.0;
    *point_char = 'n';

    printf("Depois de modificar:\nint == %d\nfloat == %.2f\n char == %c", num_int, num_float, letra);

    return 0;
}