// Looking at how 2D arrays work
// Written by Anushka, Oct. 2021

#include <stdio.h>

#define SIZE 7

#define SCALAR 3

void scalar_multiply(int rows, int columns, int arr[rows][columns], int scalar);

int main(void) {

    // Declare a (SIZE x SIZE) 2D array
    int nums[SIZE][SIZE];
    
    // Initialize every element to 1
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            nums[row][col] = 1;
            col++;
        }
        row++;
    }
    
    scalar_multiply(SIZE, SIZE, nums, 3);
    
    // Print out the array elements as a grid
    row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            printf("%d ", nums[row][col]);
            col++;
        }
        printf("\n");
        row++;
    }
    
    return 0;
}

// Take an array as input, multiply each element by a given integer
void scalar_multiply(int rows, int columns, int arr[rows][columns], int scalar) {
    int i = 0;
    while (i < rows) {
        int j = 0;
        while (j < columns) {
            arr[i][j] = arr[i][j] * scalar;
            j++;
        }
        i++;
    }
}












