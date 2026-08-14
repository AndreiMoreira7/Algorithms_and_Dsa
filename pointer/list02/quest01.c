#include <stdio.h>

typedef struct{
    char nomeBanda[50];
    int diaLancamento;
    int mesLancamento;
    int anoLancamento;
    float valorCd;
    int numMembros;
    char nomeProdutora[50];    
}cd;

int main(){
    cd cd1;

    printf("Digite o nome da banda: ");
    fgets(cd1.nomeBanda, sizeof(cd1.nomeBanda), stdin);

    printf("Qual o dia do lançamento do cd?: ");
    scanf("%d", &cd1.diaLancamento);

    printf("Qual o mês do lançamento do cd?: ");
    scanf("%d", &cd1.mesLancamento);

    printf("Qual o ano do lançamento do cd?: ");
    scanf("%d", &cd1.anoLancamento);

    printf("Qual o valor do cd?: ");
    scanf("%d", &cd1.valorCd);

    printf("Qual o numero de membros da banda?: ");
    scanf("%d", &cd1.numMembros);

    printf("Qual o nome da produtora?: ");
    fgets(cd1.nomeProdutora, sizeof(cd1.nomeProdutora), stdin);

    printf("[Nome da Banda: %s]\n[Dia do lançamento: %d]\n[Mês do lançamento: %d]\n[Ano do lançamento: %d]\n[Valor do CD: %.2f]\n[Número de membros: %d]\n[Produtora do CD: %s]", cd1.nomeBanda, cd1.diaLancamento, cd1.mesLancamento, cd1.anoLancamento, cd1.valorCd, cd1.numMembros, cd1.nomeProdutora);

    return 0;
}