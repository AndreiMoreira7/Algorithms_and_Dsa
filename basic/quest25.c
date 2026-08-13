#include <stdio.h>
#include <string.h>

void inverter_string(char str[]){

    str[strcspn(str, "\n")] = '\0';

    int i = 0;
    int j = strlen(str) - 1;
    char aux;

    while(i < j){
        aux = str[i];
        str[i] = str[j];
        str[j] = aux;
        i++;
        j--;
    }

    printf("a string invertida é [%s]", str);
}

int main(){
    char str[50];

    printf("Digite uma palavra e mostraremos ela invertida: ");
    fgets(str, sizeof(str), stdin);

    inverter_string(str);

    return 0;
}