#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vogais(char *p_frase, int tamanho_frase, int num_vogais){
    for(int i = 0; i < tamanho_frase; i++){
        *(p_frase + i) = tolower(*(p_frase + i));
        if(*(p_frase + i) == 'a' || *(p_frase + i) == 'e' || *(p_frase + i) == 'i' || *(p_frase + i) == 'o' || *(p_frase + i) == 'u'){
            num_vogais++;
        }
    }

    printf("O número de vogais é [%d]", num_vogais);
}

int main(){
    char frase[100], *p_frase;
    int tamanho_frase = 0, num_vogais = 0;
    p_frase = &frase; 

    printf("Digite uma frase e diremos o numero de vogais: ");
    fgets(frase, sizeof(frase), stdin);

    tamanho_frase = strlen(frase) - 1; 

    vogais(&p_frase[0], tamanho_frase, num_vogais);

    return 0;
}