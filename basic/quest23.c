#include <stdio.h>
#include <string.h>
#define TAMANHO 100

void contar_chars(char str[]){
    int length = strlen(str) - 1;

    printf("o número de caracteres é [%d]", length);
}

int main(){
    char str[TAMANHO];

    printf("Digite uma frase e veja o numero de caracteres: ");
    fgets(str, sizeof(str), stdin);

    contar_chars(str);

    return 0;
}