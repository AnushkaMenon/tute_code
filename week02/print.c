// Scanf and printf practice
// Reads in the number of apples from the user
//  and prints it out
// Written by Anushka, Sep. 2021

#include <stdio.h>

int main(void) {
    
    printf("hello world\n");
    
    /*
    %d - integers
    %lf - double
    %c - characters
    */
    
    printf("Enter number of apples: ");
    
    int apples;
    scanf("%d", &apples);
    
    printf("%d! That's a lot of apples!\n", apples);
    
    return 0;
}
