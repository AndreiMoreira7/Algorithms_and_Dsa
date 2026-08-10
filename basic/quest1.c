#include <stdio.h>

int main(){
    int idade = 0;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if(idade < 12 && idade > 0){
        printf("Criança!");
    }else if(idade >= 12 && idade <= 17){
        printf("Adolescente");
    }else if(idade >= 18 && idade <= 59){
        printf("Adulto");
    }else if(idade >= 60){
        printf("Idoso");
    }else{
        printf("erro, idade inválida");
    }
    return 0;
}