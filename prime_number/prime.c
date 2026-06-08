#include <stdio.h>
#include <math.h>

void prime_number(){
    int num = 0;
    
    printf("Enter a number and we'll tell you if it's prime: ");
    scanf("%d", &num);
    
    for (int i = num -1; i > sqrt(num); i--){
    	if(num % i == 0){
    		printf("the number [%d] isn't prime", num);
    		return;
		}
	}
    printf("the number [%d] is prime", num);
}


int main(){
	
	prime_number();
	
    return 0;
}
