#include <stdio.h>

typedef struct{
    const char* name;
    long long seconds;
}TimeUnit; 

TimeUnit units[] = { 
    {"year", 31536000LL},
    {"months", 2629800LL},
    {"weeks", 604800LL},
    {"days", 86400LL},
    {"hours", 3600LL},
    {"minutes", 60LL},
    {"seconds", 1LL}
};

void seconds_to_years(long long total_seconds){ 
    int num_units = sizeof(units) / sizeof(units[0]); 
    long long values[num_units]; 

    for(int i = 0; i < num_units; i++){
        values[i] = total_seconds / units[i].seconds; 
        total_seconds %= units[i].seconds; 
    }

    printf("[");
    for(int i = 0; i < num_units; i++){
        printf("%lld %s(s)%s", values[i], units[i].name, (i == num_units - 1) ? "" : ": ");
    }
    printf("]");
}

int main(){
    long long input;

    printf("input the total seconds: ");
    if(scanf("%lld", &input) == 1){
        seconds_to_years(input);
    }

    return 0;
}
