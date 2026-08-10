#include <stdio.h>


int main(){
    int num1 = 0, num2 = 0;
    char operador;

    printf("Digite dois números e o operador que deseja usar: ");
    scanf("%d %d %c", &num1, &num2, &operador);

    switch(operador){
        case '*': 
            printf("a multiplicação dos numeros %d e %d é [%d]", num1, num2, num1 * num2);
            break;
        case '/': 
            printf("a divisão dos numeros %d e %d é [%d]", num1, num2, num1 / num2);
            break;
        case '+': 
            printf("a soma dos numeros %d e %d é [%d]", num1, num2, num1 + num2);
            break;
        case '-': 
            printf("a divisão dos numeros %d e %d é [%d]", num1, num2, num1 - num2);
            break;
        default: 
            printf("operador inválido");
    }

return 0;
}