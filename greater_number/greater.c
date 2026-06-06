#include <stdio.h>

void greater(int nums[], size_t size){
    int greaterNum = nums[0];
	size_t i;

    for (i = 0; i < size; i++){
        if(nums[i] > greaterNum){
            greaterNum = nums[i];
        }
    }
    printf("The entire vector is: [");
    for (i = 0; i < size; i++){
    	printf(" %d ", nums[i]);
	}
	printf("]  and the greater number is: %d", greaterNum);
}

int main(){
    int vector[] = {50, 11, 81, 44, 70, 30}; // example of input
    size_t size = sizeof(vector) / sizeof(vector[0]);
    
    greater(vector, size); 	

    return 0;
}
