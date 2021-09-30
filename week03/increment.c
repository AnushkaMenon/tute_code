// Printing numbers from 1 to n, in increments of the user's choosing
// Written by Anushka, Sep. 2021

#include <stdio.h>

int main(void) {

    int finish;
    
    printf("Enter finish: ");
    scanf("%d", &finish);
    
    int increment;
    
    printf("Enter increment: ");
    scanf("%d", &increment);

    int i = 1;
    while (i <= finish) {
        printf("%d\n", i);
        i = i + increment;
    }

    return 0;
}

/*
Modify the program to use an increment of the user's choosing
    ./count_inc
    Enter finish: 17
    Enter increment: 5
    1
    6
    11
    16
*/
