// A program to print all positive numbers up to a given number,
//  using functions
// Written by Anushka, Oct. 2021

#include <stdio.h>

void count_up(int num);

int main(void) {

    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    
    count_up(number);
    
    count_up(5);
    
    count_up(3);
    
    return 0;
}

void count_up(int num) {
    int i = 0;
    
    while (i <= num) {
        printf("%d\n", i);
        i++;
    }
}
