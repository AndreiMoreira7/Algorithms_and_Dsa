#include <stdio.h>
#include <string.h>
#define QUANTIDADE 6

typedef struct{
    char titulo[40];
    char autor[30];
    int ano;
}Livro;

void settar_livros(Livro livros[]){
    for(int i = 0; i < QUANTIDADE; i++){
        printf("Digite o título do livro %d: ", i + 1);
        fgets(livros[i].titulo, sizeof(livros[i].titulo), stdin);

        printf("Digite o autor do livro %d: ", i + 1);
        fgets(livros[i].autor, sizeof(livros[i].autor), stdin);
        livros[i].autor[strcspn(livros[i].autor, "\n")] = "\0";

        printf("Digite o ano do livro %d: ", i + 1);
        scanf("%d", &livros[i].ano);
        while(getchar() != '\n');
    }
}

void livros_pos_2000(Livro livros[]){
    printf("\n===== LIVROS PUBLICADOS APÓS O ANO 2000 =====\n");

    for(int i = 0; i < QUANTIDADE; i++){
        if(livros[i].ano > 2000){
            printf("[TITULO: %s / AUTOR: %s / ANO: %d]\n", livros[i].titulo, livros[i].autor, livros[i].ano);
        }
    }
}

int main(){
    Livro livros[QUANTIDADE];

    settar_livros(livros);
    livros_pos_2000(livros);

    return 0;
}