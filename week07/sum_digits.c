// Program to sum the digits entered in user inputs 
// Written by Anushka, Oct. 2021

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int digits = 0;
    int sum = 0;
    
    int c;
    c = getchar();
    
    while (c != EOF) {
        if (c >= '0' && c <= '9') {
            digits++;
            sum += c - '0';
        }
    
        c = getchar();
    }
    
    printf("Digits: %d, Sum: %d\n", digits, sum);
    
    return 0;
}

/* Write a program sum_digits.c which reads characters
    from its input. When the end of input is reached it
    should print a count of the number of digits in its
    input and their sum.
    
    Example 1:
        ./sum_digits
        1 2 3 o'clock
        4 o'clock rock

        Input contained 4 digits which summed to 10
        
    Example 2:
        ./sum_digits
        12 twelve 24 twenty four
        thirty six 36

        Input contained 6 digits which summed to 18
*/
