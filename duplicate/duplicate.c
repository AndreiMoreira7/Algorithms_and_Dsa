#include <stdio.h>

void remove_duplicate(int vector[], int length){
    int new_length = 0;

    for(int i = 0; i < length; i++){
        int there_is = 0; //boolean false
        for(int j = 0; j < new_length; j++){
            if(vector[i] == vector[j]){
                there_is = 1; //true
                break;
            }
        }
        if(!there_is){
            vector[new_length++] = vector[i];
        }
    }

    printf("the array without duplicates is [");
    for(int i = 0; i != new_length; i++){
        printf(" %d ", vector[i]);
    }
    printf("]");
}


int main(){
    int vector[] = {3, 5, 7, 3, 1, 1, 10, 3, 7, 5, 1, 10, 10}; //example of input 
    int length = sizeof(vector) / sizeof(vector[0]);

    remove_duplicate(vector, length);

    return 0;
}