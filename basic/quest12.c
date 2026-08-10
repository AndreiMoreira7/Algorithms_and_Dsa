#include <stdio.h>

int main(){
    int opcao = 0;

    do{
        printf("[1. Olá!]\n[2. Adeus]\n[3. Sair]\nEscolha uma opção acima: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1: printf("Iaiiiii\n"); break;
            case 2: printf("bye byeee\n"); break;
            case 3: printf("Encerrando o programa"); break;
            default: printf("Opção inválida, tente novamente\n"); break;
        }
    }
    while(opcao != 3);

    return 0;
}