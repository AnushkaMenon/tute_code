// Printing n asterisks
// Written by Anushka, Sep. 2021

#include <stdio.h>

int main(void) {

    int num_asterisks;
    
    printf("Please enter an integer: ");
    scanf("%d", &num_asterisks);
    
    int i = 0;
    while (i < num_asterisks) {
        printf("*\n");
        i++;
    }

    return 0;
}

/*
Write a program that reads in an integer and prints out that many asterisks, each on a new line.
    ./asterisks
    Please enter an integer: 5
    *
    *
    *
    *
    *
*/
