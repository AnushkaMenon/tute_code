// Printing a square of asterisks using a 2D while loop
// Written by Anushka, Sep. 2021

#include <stdio.h>

int main(void) {

    int size;
    
    printf("Enter size: ");
    scanf("%d", &size);
    
    int row = 0;
    while (row < size) {
        int col = 0;
        
        while (col < size) {
            printf("*");
            col++;
        }
        
        printf("\n");
        row++;
    }

    return 0;
}

/*
Modify the program to print a square instead of a line
    ./square
    Enter size: 5
    *****
    *****
    *****
    *****
    *****
*/
