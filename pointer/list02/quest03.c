#include <stdio.h>
#include <string.h>
#define TAMANHO 3

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
    cd cds[TAMANHO];

    for(int i = 0; i < TAMANHO; i++){
        printf("Digite o nome da banda %d: ", i + 1);
        fgets(cds[i].nomeBanda, sizeof(cds[i].nomeBanda), stdin);
        cds[i].nomeBanda[strcspn(cds[i].nomeBanda, "\n")] = "\0"; //tira o caractere de quebra de linha que fica preso no buffer

        printf("digite o valor do cd %d: ", i + 1);
        scanf("%f", &cds[i].valorCd);

        printf("Digite o número de membros da banda do cd %d: ", i + 1);
        scanf("%d", &cds[i].numMembros);
        while(getchar() != '\n');

        printf("Digite o nome da produtora do cd %d: ", i + 1);
        fgets(cds[i].nomeProdutora, sizeof(cds[i].nomeProdutora), stdin);
        cds[i].nomeProdutora[strcspn(cds[i].nomeProdutora, "\n")] = "\0";

        printf("Digite a data do lançamento do cd %d no formato -> [d/m/a]: ", i + 1);
        scanf("%d/%d/%d", &cds[i].data_lancamento.dia, &cds[i].data_lancamento.mes, &cds[i].data_lancamento.ano);
        while(getchar() != '\n');
    }

    for(int i = 0; i < TAMANHO; i++){
        printf("\n========== [CD %d] ==========\n", i + 1);
        printf("NOME DA BANDA: %s\nVALOR DO CD: %f\nNÚMERO DE INTEGRANTES: %d\nNOME DA PRODUTORA: %s\nDATA DO LANÇAMENTO: %d/%d/%d\n", cds[i].nomeBanda, cds[i].valorCd, cds[i].numMembros, cds[i].nomeProdutora, cds[i].data_lancamento.dia, cds[i].data_lancamento.mes, cds[i].data_lancamento.ano);
    }

    return 0;
}