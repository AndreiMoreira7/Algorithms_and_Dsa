#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void is_palindrom(char word[]){
    int length = strlen(word);
    int newLength = 0;

    for(int i = 0; i < length; i++){
        if(word[i] != ' ' && word[i] != '\n'){
            word[i] = tolower((unsigned char)word[i]);
            word[newLength++] = word[i];
        }
    }

    int left = 0;
    int right = newLength - 1;
    int middle = left + (right - left) / 2;

    while(left <= middle){
        if(word[left] == word[right]){
            if(left == middle){
                printf("is palindrom");
                return;
            }
            left++;
            right--;
        }
        else{
            printf("is not palindrom");
            return;
        }
    }
}


int main(){
    char word[50];

    printf("input a word and we will verify if is palindrom: " );
    fgets(word, sizeof(word), stdin);

    is_palindrom(word);
    
    return 0;
}