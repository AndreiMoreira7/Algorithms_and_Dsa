#include <stdio.h>

void seconds_to_years(){
    int seconds, minutes, hours, days, months, years;
    printf("input the seconds: ");
    scanf("%d", &seconds);

    minutes = seconds / 60;
    seconds = seconds - (minutes * 60);
    hours = minutes / 60;
    minutes = minutes - (hours * 60);
    days = hours / 24;
    hours = hours - (days * 24);
    months = days / 30;
    days = days - (months * 30);
    years = months / 12;
    months = months - (years * 12);


    printf("[%d year(s): %d month(s): %d day(s): %d hour(s): %d minute(s): %d second(s)]", years, months, days, hours, minutes, seconds);

}

int main(){

    seconds_to_years();

    return 0;
}
