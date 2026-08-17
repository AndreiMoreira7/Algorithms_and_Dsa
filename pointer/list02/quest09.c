#include <stdio.h>
#define TAMANHO 3

typedef struct{
    int red;
    int green;
    int blue;
}Pixel;

void ler_pixeis(Pixel *pixeis){
    for(int i = 0; i < TAMANHO * TAMANHO; i++){
            printf("Digite os valores RGB do pixel [%d] nesse formato -> [R, G, B]: ", i + 1);
            scanf("%d, %d, %d", &(pixeis + i)->red, &(pixeis + i)->green, &(pixeis + i)->blue);
    }
}

void calc_media(Pixel *pixeis){
    int media_red = 0, media_green = 0, media_blue = 0;
    int quantidade = TAMANHO * TAMANHO;

    for(int i = 0; i < quantidade; i++){
            media_red += (pixeis + i)->red;
            media_green += (pixeis + i)->green;
            media_blue += (pixeis + i)->blue;
    }

    printf("\n======= MÉDIAS =======\n");
    printf("[RED: %.2f]\n[GREEN: %.2f]\n[BLUE: %.2f]", (float)media_red / quantidade, (float)media_green / quantidade, (float)media_blue / quantidade);
}

int main(){
    Pixel pixeis[TAMANHO][TAMANHO];

    ler_pixeis(&pixeis[0][0]);
    calc_media(&pixeis[0][0]);

    return 0;
}