#include <stdio.h>
#include <string.h>

void quant_palavras(char *p_frase, int *p_palavras){
    int bool = 0;
    while(bool == 0){
        if(*p_frase == ' ' && p_frase != 0 && *(p_frase + 1) != '\0'){
            *(p_palavras)++; 
        }
        if(*p_frase == '\0'){
            *(p_palavras)++;
            bool = 1;
        }
        *p_frase++;
    }

    printf("A quantidade de palavras é [%d]", *p_palavras);
}

int main(){
    char frase[100];
    int palavras = 0;

    printf("Digite uma frase e te direi a quantidade de palavras: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';

    quant_palavras(frase, &palavras);

    return 0;
}