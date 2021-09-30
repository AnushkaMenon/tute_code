// Program to print the time using structs
// Written by Anushka, September 2021

#include <stdio.h>

struct time {
    int hour;
    int minute;
    char meridiem;
};

int main(void) {

    struct time start_time;
    
    start_time.hour = 5;
    start_time.minute = 3;
    start_time.meridiem = 'a';
    
    printf("%02d:%02d %cm\n", start_time.hour, start_time.minute, start_time.meridiem);
    
    // printing specific numbers of decimal places
    // double price = 5.888;
    // printf("%.3lf\n", price);
    
    return 0;
}

/*
We want to hold the information about a particular time in the day.
We need to know the:
    hour,
    minute,
    and whether or not it is AM or PM.
    
We then want to print the time in the format: "hh:mm [ap]m"

*/
