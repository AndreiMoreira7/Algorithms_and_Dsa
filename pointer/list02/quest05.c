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

void imprimir_perimetro(quadrilatero *q){
    for(int i = 0; i < TAMANHO; i++){
        if(q->pontos[i].x == q->pontos[i].y){
            printf(" O quadrilatero %d é um quadrado e o seu perimetro é [%d]\n", i + 1, q->pontos[i].x * 4);
        }
        else{
            printf("O quadrilatero %d é um retangulo/paralelogramo e o seu perimetro é [%d]\n", i + 1, (q->pontos[i].x + q->pontos[i].y) * 2);
        }
    }
}

int main(){
    quadrilatero q;
    settar_pontos(&q); 
    imprimir_perimetro(&q);  

    return 0;
}