#include <stdio.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}data;

typedef struct{
    char nomeBanda[50];
    float valorCd;
    int numMembros;
    char nomeProdutora[50];    
    data data_lancamento;
}cd;

int main(){
    cd cd1;

    printf("Digite a data do lançamento assim -> d/m/a: ");
    scanf("%d/%d/%d", &cd1.data_lancamento.dia, &cd1.data_lancamento.mes, &cd1.data_lancamento.ano);

    printf("a data é [%d/%d/%d]", cd1.data_lancamento.dia, cd1.data_lancamento.mes, cd1.data_lancamento.ano);

    return 0;
}