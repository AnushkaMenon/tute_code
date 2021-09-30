// Printing out a triangle using a 2D while loop
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
            if (col <= row) {
                printf("*");
            } else {
                printf("-");
            }
            
            col++;
        }
        
        printf("\n");
        row++;
    }

    return 0;
}

/*
Modify the program so that it prints out a triangle like this:
    ./triangle
    Enter number: 5
    *----
    **---
    ***--
    ****-
    *****
*/
