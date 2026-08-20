#include <stdio.h>
#include <string.h>

void copiar(char *string1, char *string2, int tamanho_string){

    for(int i = 0; i < tamanho_string; i++){
        string2[i] = string1[i];
    }
}

int main(){
    char string1[50], string2[50];
    int tamanho_string = 0;

    printf("Digite uma frase: ");
    fgets(string1, sizeof(string1), stdin);
    tamanho_string = strlen(string1) - 1;

    copiar(&string1[0], &string2[0], tamanho_string);

    printf("a frase que agora está em string2 é [%s]", string2);

    return 0;
}