#include <stdio.h>
#define TAMANHO 4

typedef struct{
    int x;
    int y;
}ponto;

typedef struct{
    ponto pontos[TAMANHO];
}quadrilatero;

void settar_pontos(quadrilatero *q){
    for(int i = 0; i < TAMANHO; i++){
        printf("Digite os valores do eixo X e Y do ponto %d no formato [X Y]: ", i + 1);
        scanf("%d %d", &q->pontos[i].x, &q->pontos[i].y);
    }
}

int main(){
    quadrilatero q;
    settar_pontos(&q);   

    return 0;
}