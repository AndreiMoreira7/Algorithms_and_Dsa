#include <stdio.h>
#include <ctype.h>
#include <string.h>


void verificar_palindromo(char str[]){
    int tamanho = strlen(str);
    int novoTamanho = 0;

    for(int i = 0; i < tamanho; i++){
        if(str[i] != ' ' && str[i] != '\n' && str[i] != ','){
            str[i] = tolower(str[i]);
            str[novoTamanho++] = str[i];
        }
    }

    int pointEsquerda = 0;
    int pointDireita = novoTamanho - 1;
    int meio = pointEsquerda + (pointDireita - pointEsquerda) / 2;

    while(pointEsquerda <= meio){
        if(str[pointEsquerda] == str[pointDireita]){
            if(pointEsquerda == meio){
                printf("eh palindromo");
                return;
            }
            pointEsquerda++;
            pointDireita--;
        }
        else{
            printf("nao eh palindromo");
            return;
        }
    }
}

int main(){
    char str[100];

    printf("Digite uma palavra/frase e diremos se é palindromo: ");
    fgets(str, sizeof(str), stdin);

    verificar_palindromo(str);

    return 0;
}