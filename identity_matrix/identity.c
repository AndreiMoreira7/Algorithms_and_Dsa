#include <stdio.h>

void identify(int vector[][4], int length){

    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            if((i == j && vector[i][j] != 1) || (i != j && vector[i][j] != 0)){
                printf("is not a identity matrix");
                return;
            }
        }
    }
    printf("is a identity matrix");
}

int main(){
    int vector[4][4]= {
        {1, 0, 1, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    int length = sizeof(vector) / sizeof(vector[0]); 

    identify(vector, length);

    return 0;
}