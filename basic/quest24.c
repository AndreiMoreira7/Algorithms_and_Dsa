#include <stdio.h>
#include <string.h>
#include <ctype.h>

void contar_vogais(char str[]){
    int tamanhoString = strlen(str) - 1;
    int quantidadeVogais = 0;
    
    for(int i = 0; i <= tamanhoString; i++){
        str[i] = tolower(str[i]);

        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            quantidadeVogais++;
        }
    }

    printf("A quantidade de vogais é [%d]", quantidadeVogais);
}

int main(){
    char str[100];

    printf("Digite uma string e contaremos quantas vogais tem nela: ");
    fgets(str, sizeof(str), stdin);

    contar_vogais(str);

    return 0;
}