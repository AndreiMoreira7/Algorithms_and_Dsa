#include <stdio.h>
#include <string.h>
#define TAMANHO 5

typedef struct{
    char nome[30];
    char matricula[30];
    float notas[3];
}alunos;

void settar_alunos(alunos aluno[]){
    for(int i = 0; i < TAMANHO; i++){
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(aluno[i].nome, sizeof(aluno[i].nome), stdin);

        printf("Digite a matricula do aluno %d: ", i + 1);
        fgets(aluno[i].matricula, sizeof(aluno[i].matricula), stdin);
        aluno[i].matricula[strcspn(aluno[i].matricula, "\n")] = "\0";

        printf("Digite 3 notas do aluno %d no formato [N1 N2 N3]: ", i + 1);
        scanf("%f %f %f", &aluno[i].notas[0], &aluno[i].notas[1], &aluno[i].notas[2]);
        while(getchar() != '\n');
    }
}

void calc_media(alunos aluno[]){
    for(int i = 0; i < TAMANHO; i++){
        printf("A média do aluno %s é [%.2f]\n", aluno[i].nome, (aluno[i].notas[0] + aluno[i].notas[1] + aluno[i].notas[2]) / 3);
    }
}

int main(){
    alunos aluno[TAMANHO];

    settar_alunos(aluno);
    calc_media(aluno);

    return 0;
}