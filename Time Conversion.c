#include <stdio.h>
#include <string.h>

void timeConversion(char* s) {
    int hour, minute, second;
    char period[3];
    sscanf(s, "%2d:%2d:%2d%2s", &hour, &minute, &second, period);
    if (strcmp(period, "AM") == 0) {
        if (hour == 12) {
            hour = 0;  
        }
    } else {
        if (hour != 12) {
            hour += 12;  
        }
    }
    printf("%02d:%02d:%02d\n", hour, minute, second);
}

int main() {
    char time[11]; 
    scanf("%s", time);
    timeConversion(time);
    return 0;
}