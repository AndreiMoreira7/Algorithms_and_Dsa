#include <stdio.h>

void average(char verify){
    int length = 0;
    float vector[length + 1];
    float res = 0;

    if(verify == 'y' || verify == 'Y'){
        while (verify == 'y' || verify == 'Y'){
            printf("input the number that will stay in position [%d]: ", length);
            if (scanf("%f", &vector[length]) == 1){
                res += vector[length];
                length++;
                printf("Do you want continue?(y/n): ");
                scanf(" %c", &verify);
            }
            else{
                printf("it isn't a number. execution failed, please try again!\n");
                break;
            }
        }
        if(length != 0){
            res /= length;
        }
        printf("the average is [%.2f]", res);
    }
    else{
        printf("Okay, bye bye!");
    }

}


int main(){
    char verify;
    printf("Do you want to put integers in the array to see the average? (y/n): ");
    scanf("%c", &verify);

    average(verify);

    return 0;
}