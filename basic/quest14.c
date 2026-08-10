#include <stdio.h>

#define SENHA 1234

int main(){
    int tentativas = 0;
    int senhaDigitada = 0;

    do{
        printf("Digite a sua senha: ");
        scanf("%d", &senhaDigitada);
        tentativas++;

        if(tentativas < 3){
            if(senhaDigitada == SENHA){
                printf("Senha correta, acesso permitido.\nBem vindo!");
                break;
            }
            else{
                printf("Senha incorreta, tente novamente\n");
            }  
        }
        else{
            printf("Acesso bloqueado");
        }
    }
    while(tentativas < 3);
}