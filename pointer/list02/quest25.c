#include <stdio.h>
#include <string.h>

void modificar(char *str){
    while(*str != '\0'){
        if(*str == ' '){
            *str = '-';
        }
        *str++;
    }
}

int main(){
    char frase[100];

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';

    modificar(frase);

    printf("A frase modificada é [%s]", frase);

    return 0;
}