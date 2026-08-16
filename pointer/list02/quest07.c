#include <stdio.h>
#include <string.h>
#define TAMANHO 7

typedef struct{
    char nome[20];
    char codigo[30];
    float preco;
}Produto;

void settar_produtos(Produto produtos[]){
    for(int i = 0; i < TAMANHO; i++){
        printf("Digite o nome do produto %d: ", i + 1);
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);

        printf("Digite o código do produto %d: ", i + 1);
        fgets(produtos[i].codigo, sizeof(produtos[i].codigo), stdin);
        produtos[i].codigo[strcspn(produtos[i].codigo, "\n")] = "\0";

        printf("Digite o preço do produto %d: ", i + 1);
        scanf("%f", &produtos[i].preco);
        while(getchar() != '\n');
    }
}

void menor_e_maior(Produto produtos[], float maior_preco, float menor_preco, char nome_maior[], char nome_menor[]){
    for(int i = 0; i < TAMANHO; i++){
        if(i == 0){
            menor_preco = produtos[i].preco;
            strcpy(nome_menor, produtos[i].nome);
            maior_preco = produtos[i].preco;
            strcpy(nome_maior, produtos[i].nome);
        }
        else if(menor_preco > produtos[i].preco){
            menor_preco = produtos[i].preco;
            strcpy(nome_menor, produtos[i].nome);
        }
        else if(maior_preco < produtos[i].preco){
            maior_preco = produtos[i].preco;
            strcpy(nome_maior, produtos[i].nome);
        }
    }

    printf("Maior preço == [%s: %.2f]\nMenor preço == [%s: %.2f]", nome_maior, maior_preco, nome_menor, menor_preco);
}

int main(){
    Produto produtos[TAMANHO];
    float maior_preco = 0, menor_preco = 0;
    char nome_maior[20], nome_menor[20];

    settar_produtos(produtos);
    menor_e_maior(produtos, maior_preco, menor_preco, nome_maior, nome_menor);

    return 0;
}