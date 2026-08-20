#include <stdio.h>
#include <string.h>

void inverter(char *palavra, char *palavra_invertida){
    int tamanho_palavra = strlen(palavra);

    for(int i = tamanho_palavra - 1; i >= 0; i--){
        *palavra_invertida++ = *(palavra + i);
    }
    *palavra_invertida = '\0';
}

int main(){
    char palavra[50], palavra_invertida[50];

    printf("Digite uma palavra e mostraremos ela invertida: ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    inverter(palavra, palavra_invertida);

    printf("palavra normal -> [%s] | palavra invertida -> [%s]", palavra, palavra_invertida);

    return 0;
}