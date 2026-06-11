#include <stdio.h>

void average(int length){
    float vector[length];
    float res = 0;

    for(int i = 0; i < length; i++){
        printf("input a number that will stay in position [%d]: ", i);
        if(scanf("%f", &vector[i]) == 1){
            res += vector[i];
        }
        else{
            length = i;
            printf("it isn't a number. execution failed, please try again!\n");
            break;
        }
    }

    if(length != 0){
        res /= length;
    }
    

    printf("the average is [%.2f]", res);

}

int main(){
    int length;
    printf("input the length of vector: ");
    if(scanf("%d", &length) == 1){
        average(length);
    }

    return 0;
}