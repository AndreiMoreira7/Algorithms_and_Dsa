#include <stdio.h>

void search(int vector[], int length,  int res){

    int left = 0;
    int right = length - 1;
    int steps = 0;
    int middle = 0;

    while (left <= right){
        middle = left + (right - left) / 2;
        steps++;

        if(res == vector[middle]){
            printf("The number was found in [%d] steps", steps);
            return;
        }       
        else if(res > vector[middle]){
            left = middle + 1;
        } 
        else{
            right = middle - 1;
        }
    }

}

int main(){
    int vector[] = {11, 22, 33, 44, 55, 67, 77, 88, 99, 111};
    int length = sizeof(vector) / sizeof(vector[0]);
    int res = 0;

    printf("pick one number on array [");
    for(int i = 0; i < length; i++){
        if(i != length - 1){
            printf("%d, ", vector[i]);
        }
        else{
            printf("%d]", vector[i]);
        }
    } 

    printf(" and we will tell you in how much steps we found it: ");
    if(scanf("%d", &res) == 1){
        search(vector, length, res);
    }

    return 0;
}