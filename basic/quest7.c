#include <stdio.h>;
#include <math.h>;

int main(){
    int num = 0;

    printf("imput a number: ");
    scanf("%d", &num);

    for(int i = num - 1; i > sqrt(num); i--){
        if(num % i == 0){
            printf("this isn't a prime number");
        }
    }
    printf("this is a prime number");

    return 0;
}
