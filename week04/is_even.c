// A program to determine whether a given number is even or odd,
//  using functions
// Written by Anushka, Oct. 2021

#include <stdio.h>

int is_even(int number);

int main(void) {

    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    
    int even = is_even(num);
    
    if (even == 1) {
        printf("The number was even\n");
    } else {
        printf("The number was odd\n");
    }
    
    return 0;
}

// return 1 -> the number is even
// return 0 -> the number is odd
int is_even(int number) {
    if (number % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}
