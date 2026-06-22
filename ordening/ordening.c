#include <stdio.h>

void ordening(int vector[], int length){
    int aux = 0;
    
    for(int i = 0; i < length - 1; i++){
       for(int j = i + 1; j < length; j++){
            if(vector[j] < vector[i]){
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
       }
    }

    printf("the orderned vector[");
    for(int i = 0; i < length; i++){
        printf(" %d", vector[i]);
        if(i == length - 1){
            printf("]");
        }
        else{
            printf(",");
        }
    }
}


int main(){
    int vector[] = {54, 12, 89, 33, 76, 21, 9, 67, 45, 99, 11, 23, 56, 88, 34, 
    77, 62, 5, 91, 14, 48, 72, 39, 81, 2, 63, 27, 55, 96, 41, 
    18, 70, 85, 30, 4, 60, 13, 94, 28, 47, 82, 36, 19, 52, 75, 
    8, 66, 31, 98, 25, 43, 69, 10, 57, 84, 22, 37, 74, 92, 59, 
    3, 49, 78, 15, 26, 64, 87, 40, 53, 17, 35, 95, 6, 73, 51, 
    20, 83, 44, 97, 61, 29, 68, 16, 7, 38, 90, 46, 58, 24, 79, 
    1, 93, 32, 65, 86, 42, 50, 71, 100, 80};
    int length = sizeof(vector) / sizeof(vector[0]); 
    
    ordening(vector, length);
        
    return 0;
}