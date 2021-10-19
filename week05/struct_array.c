// Exploring at 2D struct arrays
// Written by Anushka, Oct. 2021

#include <stdio.h>

#define SIZE 5

struct array_element {
    int num;
    char letter;
};

int main(void) {

    // Declare the struct array
    struct array_element arr[SIZE][SIZE];
    
    // Initialize elements of the array
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            // Set each element's num field
            arr[row][col].num = row;
            // Set each element's letter field
            arr[row][col].letter = 'a';
            col++;
        }
        row++;
    }
    
    // Print out the array elements
    row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            printf("(%d, %c)", arr[row][col].num, arr[row][col].letter);
            col++;
        }
        printf("\n");
        row++;
    }

    return 0;
}
