#include <stdio.h>
#include <string.h>

void copiar(char *string1, char *string2){
    while (*string1++ = *string2++);
}

int main(){
    char string1[50], string2[50];

    printf("Digite uma frase: ");
    fgets(string2, sizeof(string2), stdin);

    string2[strcspn(string2, "\n")] = '\0';

    copiar(&string1[0], &string2[0]);

    printf("a frase que agora está em string1 é [%s]", string1);

    return 0;
}