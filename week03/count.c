// Printing all numbers from 1 to n
// Written by Anushka, Sep. 2021

#include <stdio.h>

int main(void) {

    int finish;
    
    printf("Enter finish: ");
    scanf("%d", &finish);

    int i = 1;
    while (i <= finish) {
        printf("%d\n", i);
        i = i + 1;
    }

    return 0;
}

/*
Modify the program to read in an integer n, then print the integers 1..n, one per line.
    ./count_up
    Enter finish: 3
    1
    2
    3
*/
